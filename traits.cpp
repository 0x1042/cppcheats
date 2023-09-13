//
// Created by 韦轩 on 2023/7/17.
//

#include "traits.h"

#include <glog/logging.h>
#include <gtest/gtest.h>

namespace tests {

TEST(testf, testf) {
    static auto vec = f<10>();

    for (const auto & item : vec) {
        LOG(INFO) << "x " << item;
    }
}
} // namespace tests