//
// Created by 韦轩 on 2023/6/18.
//

#pragma once

#include <string_view>
namespace infra {

auto convert(std::string_view str, int defval = 0) -> int;

} // namespace infra