//
// Created by 韦轩 on 2023/7/1.
//

#pragma once
#include <iostream>

class Base {
public:
    Base() = default;
    virtual ~Base() = default;
    virtual void run() { std::cerr << "Base Run..." << std::endl; }
};

class Derived1 : public Base {
public:
    Derived1() = default;
    ~Derived1() override = default;

    void run() override { std::cerr << "Derived1 Run..." << std::endl; }
};

class Derived2 : public Base {
public:
    Derived2() = default;
    ~Derived2() override = default;

    void run() override { std::cerr << "Derived2 Run..." << std::endl; }
};