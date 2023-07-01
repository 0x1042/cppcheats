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
find_package(Protobuf CONFIG REQUIRED)
find_package(tbb CONFIG REQUIRED)
find_package(zstd CONFIG REQUIRED)
find_package(ZLIB REQUIRED)
find_package(Snappy CONFIG REQUIRED)

find_package(Poco REQUIRED COMPONENTS Encodings)

add_executable(${PROJECT_NAME}
               main.cpp
               resource_manager.cpp resource_manager.h
               convert.cpp convert.h
               json.cpp json.h
               parallel.cpp parallel.h
               person.pb.h person.pb.cc
               tbb_usages.cc tbb_usages.h
               prototest.cpp prototest.h
               constant.cpp constant.h
               compressor.cpp compressor.h
               cast.cpp cast.h structbinding.cpp structbinding.h)

target_link_libraries(${PROJECT_NAME}
                      PRIVATE gflags::gflags
                      PRIVATE Folly::folly
                      PRIVATE glog::glog
                      PRIVATE GTest::gtest
                      PRIVATE GTest::gtest_main
                      PRIVATE cpr::cpr
                      PRIVATE rapidjson
                      PRIVATE TBB::tbb
                      PRIVATE Folly::folly_deps
                      PRIVATE protobuf::libprotoc
                      PRIVATE protobuf::libprotobuf
                      PRIVATE Poco::Encodings
                      PRIVATE zstd::libzstd_static
                      PRIVATE ZLIB::ZLIB
                      PRIVATE Snappy::snappy
                      /usr/local/lib/libomp.a
                      )