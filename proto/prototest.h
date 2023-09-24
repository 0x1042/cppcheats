//
// Created by 韦轩 on 2023/6/25.
//

#pragma once

#include "person.pb.h"

namespace prototest {

/**
 * @brief 
 * 
 * @param person 
 * @param dst 
 */
void message_to_string(const tutorial::Person & person, std::string & dst);

/**
 * @brief 
 * 
 * @param src 
 * @param dst 
 */
void string_to_message(const std::string & src, tutorial::Person & dst);

/**
 * @brief 
 * 
 * @param person 
 * @param dst 
 */
void message_to_json(const tutorial::Person & person, std::string & dst);

/**
 * @brief 
 * 
 * @param src 
 * @param dst 
 */
void json_to_message(const std::string & src, tutorial::Person & dst);

} // namespace prototest