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