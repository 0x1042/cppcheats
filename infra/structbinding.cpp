//
// Created by 韦轩 on 2023/7/1.
//

#include "structbinding.h"

#include <array>
#include <string>
#include <tuple>
#include <utility>

#include <glog/logging.h>
#include <gtest/gtest.h>

struct Config {
    std::string v1;
    double v2;
};

TEST(testbinding, binding1) {
    double arr[3] = {1.0, 2.0, 3.0};
    auto [a, b, c] = arr;
    LOG(INFO) << "a " << a << " b " << b << " c " << c;

    std::array<std::string, 3> str_arr = {"ab", "cd", "ef"};
    auto [s1, s2, s3] = str_arr;
    LOG(INFO) << "s1 " << s1 << " s2 " << s2 << " s3 " << s3;
}

TEST(testbinding, binding2) {
    Config c{"world", 10.24};
    auto & [v1, v2] = c;
    LOG(INFO) << "v1 " << v1 << " v2 " << v2;
}

TEST(testbinding, binding3) {
    std::tuple<int, double, std::string> tp = std::make_tuple(1, 3.14, "hello world");

    // before c17
    int idx;
    double val;
    std::string str;
    std::tie(idx, val, str) = tp;
    LOG(INFO) << "idx " << idx << " val " << val << " str " << str;

    // after c17
    auto [v1, v2, v3] = tp;
    LOG(INFO) << "v1 " << v1 << " v2 " << v2 << " v3 " << v3;
}

TEST(testbinding, binding4) {
    std::pair<std::string, int64_t> p = std::make_pair("hello", 5);
    auto [k1, k2] = p;
    LOG(INFO) << "k1 " << k1 << " k2 " << k2;
}