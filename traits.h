//
// Created by 韦轩 on 2023/7/17.
//

#pragma once

#include <vector>

struct X {
    int i{};

    operator int() const { return i; }
};

template <size_t N> constexpr auto f() noexcept {
    std::vector<X> vec;

    [&]<size_t... I>(std::index_sequence<I...>) { (vec.emplace_back(I), ...); }(std::make_index_sequence<N>());

    return vec;
}


