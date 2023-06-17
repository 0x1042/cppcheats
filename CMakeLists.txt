cmake_minimum_required(VERSION 3.25)
project(cppcheats)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(Boost_NO_WARN_NEW_VERSIONS ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)

find_package(folly CONFIG REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(RapidJSON CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(${PROJECT_NAME}
               main.cpp
               resource_manager.cpp
               resource_manager.h
               convert.cpp
               convert.h json.cpp json.h)

target_link_libraries(${PROJECT_NAME}
                      gflags::gflags
                      Folly::folly
                      glog::glog
                      GTest::gtest
                      GTest::gtest_main
                      cpr::cpr
                      rapidjson
                      Folly::folly_deps)