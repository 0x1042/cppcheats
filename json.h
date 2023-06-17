//
// Created by 韦轩 on 2023/6/18.
//

#pragma once

#include <string>
#include <unordered_map>
namespace infra {

bool parse_json_to_map(const std::string & src, std::unordered_map<std::string, std::string> & dst);

}