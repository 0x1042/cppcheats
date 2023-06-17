//
// Created by 韦轩 on 2023/6/17.
//

#include "resource_manager.h"

#include <algorithm>
#include <string>
#include <vector>

#include <cpr/api.h>
#include <cpr/cpr.h>
#include <cpr/cprtypes.h>
#include <cpr/response.h>
#include <folly/Try.h>
#include <folly/executors/GlobalExecutor.h>
#include <folly/futures/Future.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

namespace infra {

std::shared_ptr<folly::CPUThreadPoolExecutor> thread_pool() {
    static auto pool = create(10, "global_exec", true);
    return pool;
}

int get(const std::string & url, std::string & response) {
    cpr::Response resp = cpr::Get(cpr::Url{url});
    response = resp.text;
    return resp.status_code;
}

folly::Future<int> async_get(const std::string & url, std::string & response) {
    return folly::via(thread_pool().get(), [&]() { return get(url, response); });
}

folly::Future<int> batch_get(const std::vector<std::string> & urls, std::vector<std::string> & resps) {
    std::vector<folly::Future<int>> fts;
    fts.reserve(urls.size());

    resps.clear();
    resps.resize(urls.size());

    for (int i = 0; i < urls.size(); i++) {
        fts.push_back(folly::via(thread_pool().get(), [i, &urls, &resps]() { return get(urls[i], resps[i]); }));
    }
    return folly::collectAll(fts).via(folly::getGlobalCPUExecutor().get()).then([](const folly::Try<std::vector<folly::Try<int>>> & vals) {
        if (vals.hasException()) {
            LOG(ERROR) << "exception:" << vals.exception().what();
            return -1;
        }

        for (const auto & item : vals.value()) {
            if (item.hasValue()) {
                LOG(INFO) << "status code:" << item.value();
            }
        }

        return 0;
    });
}

std::shared_ptr<folly::CPUThreadPoolExecutor> create(size_t thread_num, std::string_view prefix, bool block) {
    using Executor = folly::CPUThreadPoolExecutor;
    using BQueue = folly::LifoSemMPMCQueue<folly::CPUThreadPoolExecutor::CPUTask, folly::QueueBehaviorIfFull::BLOCK>;
    using TQueue = folly::LifoSemMPMCQueue<folly::CPUThreadPoolExecutor::CPUTask, folly::QueueBehaviorIfFull::THROW>;
    size_t size = folly::CPUThreadPoolExecutor::kDefaultMaxQueueSize;
    auto factory = std::make_shared<folly::NamedThreadFactory>(prefix);

    std::shared_ptr<Executor> pool;

    if (block) {
        pool = std::make_shared<Executor>(thread_num, std::make_unique<BQueue>(size), factory);
    } else {
        pool = std::make_shared<Executor>(thread_num, std::make_unique<TQueue>(size), factory);
    }

    LOG(INFO) << "ResourceManager create " << prefix << " size " << thread_num << " block " << block;

    return pool;
}
} // namespace infra


namespace tests {

TEST(testpool, createpool) {
    auto pool1 = infra::thread_pool();
    auto pool2 = infra::thread_pool();

    ASSERT_TRUE(pool1 != nullptr);
    ASSERT_TRUE(pool2 != nullptr);
}


TEST(asyncget, asyncget) {
    LOG(INFO) << "asyncget start";
    std::string resp;
    std::string url = "https://www.cnblogs.com/chenyangyao/p/folly-future.html";
    folly::Future<int> ft = infra::async_get(url, resp);
    LOG(INFO) << "asyncget fetch";
    int status_code = std::move(ft).get();

    LOG(INFO) << "asyncget fetch status_code:" << status_code << " response size:" << resp.size();
}


TEST(batchget, batchget) {
    std::vector<std::string> urls = {
        "https://mp.weixin.qq.com/s/L-ML-hkKwbOC71F6cGL3mw",
        "https://gocn.vip/c/3lQ6GbD5ny/home",
        "https://juejin.cn/",
    };

    std::vector<std::string> resp;
    folly::Future<int> ft = infra::batch_get(urls, resp);
    std::move(ft).get();
    for (const auto & item : resp) {
        LOG(INFO) << "resp:" << item.size();
    }
}

} // namespace tests