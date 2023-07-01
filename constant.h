//
// Created by 韦轩 on 2023/6/29.
//

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Constant {
public:
    static std::unordered_map<std::string, std::vector<std::string>> config1;

    static inline std::unordered_map<std::string, std::vector<std::string>> config2 = {
        {"1", {"1", "2", "3"}},
        {"2", {"4", "5", "6"}},
    };
};
