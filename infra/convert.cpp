//
// Created by 韦轩 on 2023/6/18.
//

#include "convert.h"

#include <string>

#include <folly/Conv.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

namespace infra {

auto convert(std::string_view str, int defval) -> int {
    return folly::tryTo<int>(str).value_or(defval);
}
} // namespace infra

namespace tests {

TEST(convertstr, convertstr) {
    int val = infra::convert("10");
    ASSERT_EQ(val, 10);

    int val2 = infra::convert("str", 100);
    ASSERT_EQ(val2, 100);

    std::string hw = folly::to<std::string>("hello", "world");
    ASSERT_EQ(hw, "helloworld");
}
} // namespace tests