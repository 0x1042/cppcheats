//
// Created by 韦轩 on 2023/6/17.
//

#pragma once

#include <memory>
#include <vector>

#include <folly/executors/CPUThreadPoolExecutor.h>
#include <folly/futures/Future.h>

namespace infra {

/**
 * @brief 
 * 
 * @param thread_num 线程数量 
 * @param prefix 线程名前缀
 * @param block 队列类型 
 * @return std::shared_ptr<folly::CPUThreadPoolExecutor> 
 */
static std::shared_ptr<folly::CPUThreadPoolExecutor> create(size_t thread_num, std::string_view prefix, bool block = false);

static std::shared_ptr<folly::CPUThreadPoolExecutor> thread_pool();

/**
 * @brief http get request
 * 
 * @param url target url 
 * @param response response content
 * @return int status code
 */
int get(const std::string & url, std::string & response);

folly::Future<int> async_get(const std::string & url, std::string & response);

folly::Future<int> batch_get(const std::vector<std::string> & urls, std::vector<std::string> & resps);


} // namespace infra
