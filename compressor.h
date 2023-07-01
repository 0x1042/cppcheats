//
// Created by 韦轩 on 2023/7/1.
//

#pragma once
#include <cstdint>
#include <string>

#include <zlib.h>
namespace infra {

enum class Type : uint32_t {
    UNKNOWN = 0,
    ZSTD = 1,
    SNAPPY = 2,
    DEFLATE = 3, // RFC 1951
    ZLIB = 4, // RFC 1950
    GZIP = 5, // RFC 1952  https://pkg.go.dev/compress/gzip
};

constexpr int WB_DEFLATE = -MAX_WBITS;
constexpr int WB_ZLIB = MAX_WBITS;
constexpr int WB_GZIP = MAX_WBITS | 16;

constexpr int buf_size = 16 * 1024;

constexpr int DEFAULT_LEVEL = 5;

struct CompressOptions {
    const Type type;
    const int level; // ignore by snappy

    explicit CompressOptions(Type type, int level = DEFAULT_LEVEL);
};

class Compressor {
public:
    static bool compress(const std::string & src, std::string & dst, const CompressOptions & ops);

    static bool decompress(const std::string & src, std::string & dst, const CompressOptions & ops);

private:
    static bool zstd_compress(const std::string & src, std::string & dst, int level = DEFAULT_LEVEL);

    static bool zstd_decompress(const std::string & src, std::string & dst);

    static bool snappy_compress(const std::string & src, std::string & dst);

    static bool snappy_decompress(const std::string & src, std::string & dst);

    static bool zlib_compress(const std::string & src, std::string & dst, int wb, int level = DEFAULT_LEVEL);

    static bool zlib_decompress(const std::string & src, std::string & dst, int wb);
};
} // namespace infra
