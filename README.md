# cppcheats

> 工作中常用的库

| 库                                                      | 使用到的功能        |
| ------------------------------------------------------- | ------------------- |
| [folly](https://github.com/facebook/folly)              | 线程池/异步任务封装 |
| [rapidjson](https://github.com/Tencent/rapidjson)       | json解析/生成       |
| [protobuf](https://github.com/protocolbuffers/protobuf) | protobuf读写        |
| [zstd](https://github.com/facebook/zstd)                | 压缩                |
| [snappy](https://github.com/google/snappy)              | 压缩                |
| [zlib](https://github.com/madler/zlib)                  | 压缩                |
| [fmt](https://github.com/fmtlib/fmt)                    | format              |
| [cpr](https://github.com/libcpr/cpr)                    | http request        |
| [thrift](https://github.com/apache/thrift)              | rpc协议             |
| [tbb](https://github.com/oneapi-src/oneTBB)             | 线程安全的容器      |
| [openmp](https://www.openmp.org/)                       | 并行计算            |
| [Log4cxx](https://github.com/apache/logging-log4cxx)    | 日志                |
| [jemalloc](https://github.com/jemalloc/jemalloc)        | 内存分配            |
| [cityhash](https://github.com/google/cityhash)          | hash                |

- [cppcheats](#cppcheats)
- [folly](#folly)
  - [线程池](#线程池)
  - [异步封装](#异步封装)
  - [执行多个异步任务](#执行多个异步任务)
  - [类型转换](#类型转换)
- [rapidjson](#rapidjson)
  - [parse json](#parse-json)
  - [generate json](#generate-json)
- [openmp](#openmp)
- [protobuf](#protobuf)
  - [数据类型](#数据类型)
  - [序列化/反序列化](#序列化反序列化)
  - [编码规则](#编码规则)
  - [arean](#arean)
  - [json convert](#json-convert)
  - [反射](#反射)
- [thrift](#thrift)
  - [数据类型](#数据类型-1)
  - [序列化/反序列化](#序列化反序列化-1)
  - [编码规则](#编码规则-1)
- [zstd](#zstd)
  - [压缩](#压缩)
  - [解压](#解压)
- [snappy](#snappy)
  - [压缩](#压缩-1)
  - [解压](#解压-1)
- [zlib](#zlib)
  - [压缩](#压缩-2)
  - [解压](#解压-2)
- [tbb](#tbb)
  - [线程安全的容器](#线程安全的容器)
  - [并行算法](#并行算法)
  - [并行循环](#并行循环)

# folly 

## 线程池 

```c++
std::shared_ptr<folly::CPUThreadPoolExecutor> thread_pool() {
    static auto pool = create(10, "global_exec", true);
    return pool;
}

std::shared_ptr<folly::CPUThreadPoolExecutor> create(size_t thread_num, std::string_view prefix, bool block) {
    using Executor = folly::CPUThreadPoolExecutor;
    using BQueue = folly::LifoSemMPMCQueue<folly::CPUThreadPoolExecutor::CPUTask, folly::QueueBehaviorIfFull::BLOCK>;
    using TQueue = folly::LifoSemMPMCQueue<folly::CPUThreadPoolExecutor::CPUTask, folly::QueueBehaviorIfFull::THROW>;
    size_t size = folly::CPUThreadPoolExecutor::kDefaultMaxQueueSize;
    auto factory = std::make_shared<folly::NamedThreadFactory>(prefix);

    std::shared_ptr<Executor> pool;

    if (block) {
        pool = std::make_shared<Executor>(thread_num, std::make_unique<BQueue>(size), factory);
    } else {
        pool = std::make_shared<Executor>(thread_num, std::make_unique<TQueue>(size), factory);
    }

    LOG(INFO) << "ResourceManager create " << prefix << " size " << thread_num << " block " << block;

    return pool;
}
```

## 异步封装 

```c++
int get(const std::string & url, std::string & response) {
    cpr::Response resp = cpr::Get(cpr::Url{url});
    response = resp.text;
    return resp.status_code;
}

folly::Future<int> async_get(const std::string & url, std::string & response) {
    return folly::via(thread_pool().get(), [&]() { return get(url, response); });
}
```

## 执行多个异步任务

```c++
folly::Future<int> batch_get(const std::vector<std::string> & urls, std::vector<std::string> & resps) {
    std::vector<folly::Future<int>> fts;
    fts.reserve(urls.size());

    resps.clear();
    resps.resize(urls.size());

    for (int i = 0; i < urls.size(); i++) {
        fts.push_back(folly::via(thread_pool().get(), [i, &urls, &resps]() { return get(urls[i], resps[i]); }));
    }
    return folly::collectAll(fts).via(folly::getGlobalCPUExecutor().get()).then([](const folly::Try<std::vector<folly::Try<int>>> & vals) {
        if (vals.hasException()) {
            LOG(ERROR) << "exception:" << vals.exception().what();
            return -1;
        }

        for (const auto & item : vals.value()) {
            if (item.hasValue()) {
                LOG(INFO) << "status code:" << item.value();
            }
        }

        return 0;
    });
}
```

## 类型转换

```c++

int convert(std::string_view str, int defval) {
    return folly::tryTo<int>(str).value_or(defval);
}

std::string hw = folly::to<std::string>("hello", "world");
ASSERT_EQ(hw, "helloworld");

```

# rapidjson 

## parse json

```c++
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
```

## generate json

```c++
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
```

# openmp 


# protobuf 

## 数据类型 

## 序列化/反序列化 

## 编码规则

## arean

## json convert 

## 反射 


# thrift 

## 数据类型 

## 序列化/反序列化 

## 编码规则


# zstd 

## 压缩

## 解压 

# snappy 

## 压缩

## 解压 

# zlib 

## 压缩

## 解压 


# tbb

> https://www.cnblogs.com/KillerAery/p/16333348.html#cpu-bound-%E4%B8%8E-memory-bound 

## 线程安全的容器 


## 并行算法 

- map
- reduce
- filter
- scan

## 并行循环