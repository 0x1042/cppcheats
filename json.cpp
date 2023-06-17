//
// Created by 韦轩 on 2023/6/18.
//

#include "json.h"

#include <string>
#include <unordered_map>
#include <utility>

#include <fmt/format.h>
#include <fmt/ranges.h>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>

namespace infra {

bool parse_json_to_map(const std::string & src, std::unordered_map<std::string, std::string> & dst) {
    rapidjson::Document doc;
    doc.Parse(src.c_str());

    if (doc.HasParseError()) {
        LOG(ERROR) << "parse fail,error:" << doc.GetParseError();
        return false;
    }

    if (!doc.IsObject()) {
        return false;
    }

    for (const auto & elem : doc.GetObject()) {
        if (elem.value.IsString()) {
            dst.insert(std::make_pair(elem.name.GetString(), elem.value.GetString()));
        }
    }
    return !dst.empty();
}
} // namespace infra


namespace tests {

TEST(jsonparse, jsonparse) {
    std::string str = "{\n"
                      "    \"sang\":\"dress\",\n"
                      "    \"happily\":\"repeat\",\n"
                      "    \"four\":\"dress\",\n"
                      "    \"condition\":\"morning\",\n"
                      "    \"grow\":\"review\",\n"
                      "    \"silver\":\"tin\"\n"
                      "}";

    std::unordered_map<std::string, std::string> db;

    infra::parse_json_to_map(str, db);

    LOG(INFO) << fmt::to_string(db);
}
} // namespace tests