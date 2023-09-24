#pragma once

#include <coroutine>

struct FibGenerator {
    struct promise_type {
        std::experimental::suspend_always initial_suspend() { return {}; }
    };
};

FibGenerator my_range(int x) {
    while (true) {
        co_yield x;
        ++x;
    }
}