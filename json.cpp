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
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

namespace infra {

bool json_to_map(const std::string & src, std::unordered_map<std::string, std::string> & dst) {
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

bool generate_json(std::string & dst) {
    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType & allocator = doc.GetAllocator();

    rapidjson::Value array(rapidjson::kArrayType);

    rapidjson::Value hello_value(rapidjson::kStringType);
    hello_value.SetString("hello");

    rapidjson::Value world_value(rapidjson::kStringType);
    world_value.SetString("world");

    array.PushBack(hello_value, allocator);
    array.PushBack(world_value, allocator);
    doc.AddMember("array", array, allocator);

    rapidjson::Value person(rapidjson::kObjectType);
    person.AddMember("age", 20, allocator);

    rapidjson::Value email_value(rapidjson::kStringType);
    email_value.SetString("test@test.com");
    person.AddMember("email", email_value, allocator);
    doc.AddMember("person", person, allocator);

    doc.AddMember("data_size", 1, allocator);

    rapidjson::StringBuffer buf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buf);

    doc.Accept(writer);

    dst = buf.GetString();

    return true;
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

    infra::json_to_map(str, db);

    LOG(INFO) << fmt::to_string(db);
}

TEST(generatejson, generatejson) {
    std::string resp;
    infra::generate_json(resp);
    LOG(INFO) << "resp:" << resp;
}

} // namespace tests