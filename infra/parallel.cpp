//
// Created by 韦轩 on 2023/6/18.
//

#include "parallel.h"

#include <algorithm>
#include <string>
#include <vector>

#include <omp.h>

#include <gtest/gtest.h>

#include "resource_manager.h"
namespace infra {

void parallel_job() {
    std::vector<std::string> urls = {
        "https://mp.weixin.qq.com/s/L-ML-hkKwbOC71F6cGL3mw",
        "https://gocn.vip/c/3lQ6GbD5ny/home",
        "https://juejin.cn/",
        "https://www.bilibili.com/video/BV1sQ4y1P7f7/?spm_id_from=autoNext&vd_source=f9558841d6c38478cc2a792ff9cfe046",
    };

    std::vector<std::string> resp;
    resp.resize(urls.size());
    // https: //610yilingliu.github.io/2020/07/15/ScheduleinOpenMP/
    // #pragma omp parallel for schedule(dynamic, chunk - size)

    // #pragma omp parallel for schedule(dynamic, 2) num_threads(4)
    omp_set_num_threads(4);
// #pragma omp parallel for schedule(static, 1)
#pragma omp parallel for
    for (int i = 0; i < urls.size(); i++) {
        LOG(INFO) << "omp_in_parallel:" << omp_in_parallel() << "\tstatus code:" << get(urls[i], resp[i]);
    }
    std::for_each(resp.begin(), resp.end(), [](const std::string & content) { LOG(INFO) << "content length:" << content.size(); });
}

} // namespace infra

namespace tests {

TEST(testrun, testrun) {
    infra::parallel_job();
}
} // namespace tests