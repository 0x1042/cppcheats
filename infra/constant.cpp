//
// Created by 韦轩 on 2023/6/29.
//

#include "constant.h"

#include <fmt/format.h>
#include <fmt/ranges.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

std::unordered_map<std::string, std::vector<std::string>> Constant::config1 = {
    {"3", {"1", "2", "3"}},
    {"4", {"4", "5", "6"}},
};

namespace tests {

TEST(teststatic, teststatic) {
    LOG(INFO) << "config1:" << fmt::to_string(Constant::config1);
    LOG(INFO) << "config2:" << fmt::to_string(Constant::config2);
}
} // namespace tests