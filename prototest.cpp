//
// Created by 韦轩 on 2023/6/25.
//

#include "prototest.h"

#include <memory>
#include <string>

#include <glog/logging.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/stubs/status.h>
#include <google/protobuf/util/json_util.h>
#include <gtest/gtest.h>

#include <Poco/Base64Decoder.h>
#include <Poco/Base64Encoder.h>

#include "person.pb.h"

namespace prototest {
void message_to_string(const tutorial::Person & person, std::string & dst) {
    if (bool status = person.SerializeToString(&dst); !status) {
        LOG(ERROR) << "marshal fail";
    }
}

void string_to_message(const std::string & src, tutorial::Person & dst) {
    if (bool status = dst.ParseFromString(src); !status) {
        LOG(ERROR) << "unmarshal fail";
    }
}

void message_to_json(const tutorial::Person & person, std::string & dst) {
    google::protobuf::util::JsonOptions opt;

    opt.preserve_proto_field_names = true;
    google::protobuf::util::Status status = google::protobuf::util::MessageToJsonString(person, &dst, opt);

    if (!status.ok()) {
        LOG(INFO) << "convert message to json fail." << status.message();
    }
}

void json_to_message(const std::string & src, tutorial::Person & dst) {
    google::protobuf::util::JsonParseOptions opt;

    opt.ignore_unknown_fields = true;

    google::protobuf::util::Status status = google::protobuf::util::JsonStringToMessage(src, &dst, opt);
    if (!status.ok()) {
        LOG(INFO) << "convert json to message fail." << status.message();
    }
}
} // namespace prototest

namespace tests {

TEST(prototest, messagetostring) {
    auto person = std::make_shared<tutorial::Person>();

    person->set_id(1024);
    person->set_age(20);
    person->set_name("tom");
    person->set_gender(tutorial::Gender::MALE);
    person->set_role(tutorial::Role::SOLDIER);
    auto * num = person->mutable_numbers();

    tutorial::PhoneNumber work;
    work.set_number("139-999-9999");
    work.set_pt(tutorial::PhoneType::WORK);
    num->Add(std::move(work));

    tutorial::PhoneNumber mobile;
    mobile.set_number("139-999-8888");
    mobile.set_pt(tutorial::PhoneType::MOBILE);
    num->Add(std::move(mobile));

    auto * extra = person->mutable_extras();
    (*extra)["hello"] = "world";
    (*extra)["hello1"] = "world1";
    (*extra)["hello2"] = "world2";

    std::string rsp;

    prototest::message_to_string(*person, rsp);

    std::stringstream ss;
    ss.str("");

    Poco::Base64Encoder encoder(ss);
    encoder << rsp;
    encoder.close();

    LOG(INFO) << "rsp:" << rsp << "|";

    std::string str = ss.str();

    LOG(INFO) << "rsp:" << rsp << "|";
    LOG(INFO) << "str:" << str << "|";

    ASSERT_EQ(3, person->extras().size());
    ASSERT_GT(str.size(), 0);
}

TEST(prototest, stringtomessage) {
    auto person = std::make_shared<tutorial::Person>();

    person->set_id(1024);
    person->set_age(20);
    person->set_name("tom");
    person->set_gender(tutorial::Gender::MALE);
    person->set_role(tutorial::Role::SOLDIER);
    auto * num = person->mutable_numbers();

    tutorial::PhoneNumber work;
    work.set_number("139-999-9999");
    work.set_pt(tutorial::PhoneType::WORK);
    num->Add(std::move(work));

    tutorial::PhoneNumber mobile;
    mobile.set_number("139-999-8888");
    mobile.set_pt(tutorial::PhoneType::MOBILE);
    num->Add(std::move(mobile));

    auto * extra = person->mutable_extras();
    (*extra)["hello"] = "world";
    (*extra)["hello1"] = "world1";
    (*extra)["hello2"] = "world2";

    std::string str;
    prototest::message_to_string(*person, str);

    auto person2 = std::make_shared<tutorial::Person>();

    prototest::string_to_message(str, *person2);

    LOG(INFO) << "extra:" << person2->extras_size();
    ASSERT_EQ(person2->name(), "tom");
    ASSERT_EQ(person2->extras_size(), 3);
}

TEST(prototest, createarean) {
    google::protobuf::ArenaOptions opt;
    opt.initial_block_size = 1024 * 16;
    google::protobuf::Arena arena(opt);

    tutorial::Person * person = google::protobuf::Arena::CreateMessage<tutorial::Person>(&arena);

    person->set_age(20);
    person->set_id(1024);
    person->set_name("jerry");

    auto * extra = person->mutable_extras();
    (*extra)["hello"] = "world";
    (*extra)["hello1"] = "world1";
    (*extra)["hello2"] = "world2";

    LOG(INFO) << "person:" << person->DebugString();
}
} // namespace tests