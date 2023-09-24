#pragma once
#include <type_traits>

#include <glog/logging.h>
#include <gtest/gtest.h>

//https://www.notion.so/C-939394f0f7914a598658ad834c5b50ab
template <typename T> class ShowType {};

TEST(testv1, showtype) {
    // T = int
    auto st1 = ShowType<int>();
    // T = int&
    auto st2 = ShowType<std::add_lvalue_reference_t<int>>();

    // T = bool
    auto st3 = ShowType<std::bool_constant<true>::type>();
}

// fallback T != U
template <typename T, typename U> struct IsSame : std::false_type {};
// 特化 编译器会优先匹配，T == U
template <typename T> struct IsSame<T, T> : std::true_type {};

// 判断两个类型是否相等
TEST(testv1, testeq) {
    // ShowType<std::bool_constant<IsSame<int, int>>>();
}