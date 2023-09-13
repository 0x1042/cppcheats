//
// Created by 韦轩 on 2023/7/13.
//

#pragma once
#include <memory>

template <typename Callable> class Proxy {
private:
    Callable callable_;

public:
    explicit Proxy(Callable callable) : callable_{std::move(callable)} {}

    template <typename... Args> decltype(auto) operator()(Args... args) { return std::invoke(callable_, std::forward<Args>(args)...); }
};
