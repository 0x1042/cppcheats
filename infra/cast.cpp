//
// Created by 韦轩 on 2023/7/1.
//

#include "cast.h"

#include <unordered_map>
#include <glog/logging.h>
#include <gtest/gtest.h>

namespace tests {

TEST(testcast, testconstcast) {
    const std::string str = "hello world";

    const char * c_str = str.c_str(); // c_str 是cost object

    char * no_const_str = const_cast<char *>(c_str);

    LOG(INFO) << "no_const_str:" << no_const_str;
}

TEST(testcast, teststaticcast) {
    int num = 1024;
    double num_d = static_cast<double>(num);
    LOG(INFO) << "num_d:" << num_d;

    // upcast
    Derived2 * d_ptr = new Derived2{};
    Base * b_ptr = static_cast<Base *>(d_ptr);
    LOG(INFO) << "b_ptr:" << b_ptr;

    // 失败
    //    Base * base_ptr = new Base{};
    //    Derived2 * d2_ptr = static_cast<Derived2 *>(base_ptr);
    //    LOG(INFO) << "d2_ptr:" << d2_ptr;
}

TEST(testcast, testreinterpretcast) {
    Base * b_ptr1 = new Base();
    Derived1 * d1_ptr = new Derived1();
    Derived2 * d2_ptr = new Derived2();
    Base * b_ptr2 = new Base();

    d1_ptr = reinterpret_cast<Derived1 *>(b_ptr1);
    b_ptr2 = reinterpret_cast<Base *>(d2_ptr);

    LOG(INFO) << "d1_ptr:" << d1_ptr;
    LOG(INFO) << "d2_ptr:" << d2_ptr;
}

TEST(testcast, testdynamiccast) {
    Base b;
    Base * b_ptr;
    Derived1 d;
    Derived1 * d_ptr;
    b_ptr = dynamic_cast<Base *>(&d);
    b_ptr->run(); // 调用的是子类的方法

    // will fail
    d_ptr = dynamic_cast<Derived1 *>(&b);
    //    d_ptr->run();
}
} // namespace tests