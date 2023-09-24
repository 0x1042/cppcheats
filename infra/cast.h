//
// Created by 韦轩 on 2023/7/1.
//

#pragma once
#include <iostream>

class Base {
public:
    Base() = default;
    Base(const Base &) = default;
    Base(Base &&) = delete;
    auto operator=(const Base &) -> Base & = default;
    auto operator=(Base &&) -> Base & = delete;
    virtual ~Base() = default;
    virtual void run() { std::cerr << "Base Run..." << '\n'; }
};

class Derived1 : public Base {
public:
    Derived1() = default;
    Derived1(const Derived1 &) = default;
    Derived1(Derived1 &&) = delete;
    auto operator=(const Derived1 &) -> Derived1 & = default;
    auto operator=(Derived1 &&) -> Derived1 & = delete;
    ~Derived1() override = default;

    void run() override { std::cerr << "Derived1 Run..." << '\n'; }
};

class Derived2 : public Base {
public:
    Derived2() = default;
    Derived2(const Derived2 &) = default;
    Derived2(Derived2 &&) = delete;
    auto operator=(const Derived2 &) -> Derived2 & = default;
    auto operator=(Derived2 &&) -> Derived2 & = delete;
    ~Derived2() override = default;

    void run() override { std::cerr << "Derived2 Run..." << '\n'; }
};