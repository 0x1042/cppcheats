//
// Created by 韦轩 on 2023/7/1.
//

#include "compressor.h"

#include <array>
#include <string>

#include <snappy.h>
#include <zlib.h>
#include <zstd.h>

#include <glog/logging.h>
#include <gtest/gtest.h>

namespace infra {

CompressOptions::CompressOptions(Type type, int level) : type(type), level(level) {
}

auto Compressor::compress(const std::string & src, std::string & dst, const CompressOptions & ops) -> bool {
    switch (ops.type) {
        case Type::ZSTD:
            return zstd_compress(src, dst, ops.level);
        case Type::SNAPPY:
            return snappy_compress(src, dst);
        case Type::DEFLATE:
            return zlib_compress(src, dst, WB_DEFLATE, ops.level);
        case Type::ZLIB:
            return zlib_compress(src, dst, WB_ZLIB, ops.level);
        case Type::GZIP:
            return zlib_compress(src, dst, WB_GZIP, ops.level);
        case Type::UNKNOWN:
            break;
    }
    LOG(ERROR) << "unsupport compresss type." << static_cast<uint32_t>(ops.type);
    return false;
}

auto Compressor::decompress(const std::string & src, std::string & dst, const CompressOptions & ops) -> bool {
    switch (ops.type) {
        case Type::ZSTD:
            return zstd_decompress(src, dst);
        case Type::SNAPPY:
            return snappy_decompress(src, dst);
        case Type::DEFLATE:
            return zlib_decompress(src, dst, WB_DEFLATE);
        case Type::ZLIB:
            return zlib_decompress(src, dst, WB_ZLIB);
        case Type::GZIP:
            return zlib_decompress(src, dst, WB_GZIP);
        case Type::UNKNOWN:
            break;
    }

    LOG(ERROR) << "unsupport decompress type." << static_cast<uint32_t>(ops.type);
    return false;
}

auto Compressor::zstd_compress(const std::string & src, std::string & dst, int level) -> bool {
    size_t bsize = ZSTD_compressBound(src.size());
    dst.resize(bsize);

    auto * dstp = const_cast<void *>(static_cast<const void *>(dst.c_str()));
    const auto * srcp = static_cast<const void *>(src.c_str());

    size_t size = ZSTD_compress(dstp, bsize, srcp, src.size(), level);

    if (auto code = ZSTD_isError(size); code) {
        return false;
    }
    dst.resize(size);
    return true;
}

auto Compressor::zstd_decompress(const std::string & src, std::string & dst) -> bool {
    size_t bsize = ZSTD_getFrameContentSize(src.c_str(), src.size());

    if (0 == bsize) {
        return bsize;
    }

    if (ZSTD_CONTENTSIZE_ERROR == bsize) {
        return false;
    }

    dst.resize(bsize);
    auto * dstp = const_cast<void *>(static_cast<const void *>(dst.c_str()));
    const auto * srcp = static_cast<const void *>(src.c_str());
    size_t const size = ZSTD_decompress(dstp, bsize, srcp, src.size());
    if (auto code = ZSTD_isError(size); code) {
        return false;
    }
    dst.resize(size);
    return true;
}

auto Compressor::snappy_compress(const std::string & src, std::string & dst) -> bool {
    size_t size = snappy::Compress(src.data(), src.size(), &dst);
    return size > 0;
}

auto Compressor::snappy_decompress(const std::string & src, std::string & dst) -> bool {
    return snappy::Uncompress(src.data(), src.size(), &dst);
}

auto Compressor::zlib_compress(const std::string & src, std::string & dst, int wb, int level) -> bool {
    z_stream zs;
    memset(&zs, 0, sizeof(zs));

    if (int status = deflateInit2(&zs, level, Z_DEFLATED, wb, MAX_MEM_LEVEL, Z_DEFAULT_STRATEGY); status != Z_OK) {
        LOG(ERROR) << "deflateInit failed. status:" << status;
        return false;
    }

    zs.next_in = (Bytef *)src.data();
    zs.avail_in = src.size(); // set the z_stream's input

    int ret;
    char outbuffer[buf_size];
    std::string outstring;

    // retrieve the compressed bytes blockwise
    do {
        zs.next_out = reinterpret_cast<Bytef *>(outbuffer);
        zs.avail_out = sizeof(outbuffer);

        ret = deflate(&zs, Z_FINISH);

        if (dst.size() < zs.total_out) {
            dst.append(outbuffer, zs.total_out - outstring.size());
        }
    } while (ret == Z_OK);

    deflateEnd(&zs);

    if (ret != Z_STREAM_END) {
        LOG(ERROR) << "compress fail. code:" << ret << " error:" << zs.msg;
        return false;
    }

    return true;
}

auto Compressor::zlib_decompress(const std::string & src, std::string & dst, int wb) -> bool {
    z_stream zs;
    memset(&zs, 0, sizeof(zs));

    if (int status = inflateInit2(&zs, wb); status != Z_OK) {
        LOG(ERROR) << "inflateInit failed.status:" << status;
        return false;
    }

    zs.next_in = (Bytef *)src.data();
    zs.avail_in = src.size();

    int ret;
    char outbuffer[buf_size];

    // std::array<char, buf_size> outbuffer;

    do {
        zs.next_out = reinterpret_cast<Bytef *>(outbuffer);
        zs.avail_out = sizeof(outbuffer);

        ret = inflate(&zs, 0);

        if (dst.size() < zs.total_out) {
            dst.append(outbuffer, zs.total_out - dst.size());
        }
    } while (ret == Z_OK);

    inflateEnd(&zs);

    if (ret != Z_STREAM_END) {
        LOG(ERROR) << "compress fail. code:" << ret << " error:" << zs.msg;
        return false;
    }

    return true;
}

} // namespace infra

namespace tests {

static std::string data
    = "After some patent disputes with the unix compress utility, the GZIP format was developed in 1992 by Jean-loup Gailly and Mark Adler "
      "using a new implementation of DEFLATE that did not infringe on any patents.\n"
      "\n"
      "Unlike ZIP, it is not an archive format. This means it can not compress several files or directories, it just compresses a single "
      "file or stream of data. That's why it's frequently combined with the tar utility which can create an archive of files, directories "
      "and their attributes in a single file which is then compressed with GZIP. This popular format is called tarball and its files end "
      "in .tar.gz. Tarballs do not provide access to the files contained, instead the whole file needs to be read and decompressed in "
      "memory before the directory structure can be shown.\n"
      "\n"
      "It has a GZIP wrapper on the compressed data with the filename and other system information, and a CRC-32 checksum at the end to "
      "check the integrity of the data. On the other hand, the final size is usually smaller than zip since it does take advantage of "
      "redundancy across files.";

TEST(compress, compresszstd) {
    infra::CompressOptions opts{infra::Type::ZSTD, 5};

    std::string out;
    bool status = infra::Compressor::compress(data, out, opts);
    LOG(INFO) << "origin size:" << data.size() << " after compressed size:" << out.size() << " compress status:" << status;
    ASSERT_TRUE(status);
    ASSERT_GT(out.size(), 0);

    std::string de_out;

    bool status2 = infra::Compressor::decompress(out, de_out, opts);

    LOG(INFO) << "origin size:" << out.size() << " after decompressed size:" << de_out.size() << " compress status:" << status2;
    ASSERT_TRUE(status2);
    ASSERT_GT(out.size(), 0);
}

TEST(compress, compresssnappy) {
    infra::CompressOptions opts{infra::Type::DEFLATE, 0};

    std::string out;
    bool status = infra::Compressor::compress(data, out, opts);
    LOG(INFO) << "origin size:" << data.size() << " after compressed size:" << out.size() << " compress status:" << status;
    ASSERT_TRUE(status);
    ASSERT_GT(out.size(), 0);

    std::string de_out;

    bool status2 = infra::Compressor::decompress(out, de_out, opts);

    LOG(INFO) << "origin size:" << out.size() << " after decompressed size:" << de_out.size() << " compress status:" << status2;
    ASSERT_TRUE(status2);
    ASSERT_GT(out.size(), 0);
}

TEST(compress, compressdeflate) {
    infra::CompressOptions opts{infra::Type::DEFLATE, 5};

    std::string out;
    bool status = infra::Compressor::compress(data, out, opts);
    LOG(INFO) << "origin size:" << data.size() << " after compressed size:" << out.size() << " compress status:" << status;
    ASSERT_TRUE(status);
    ASSERT_GT(out.size(), 0);

    std::string de_out;

    bool status2 = infra::Compressor::decompress(out, de_out, opts);

    LOG(INFO) << "origin size:" << out.size() << " after decompressed size:" << de_out.size() << " compress status:" << status2;
    ASSERT_TRUE(status2);
    ASSERT_GT(out.size(), 0);
}

TEST(compress, compresszlib) {
    infra::CompressOptions opts{infra::Type::ZLIB, 5};

    std::string out;
    bool status = infra::Compressor::compress(data, out, opts);
    LOG(INFO) << "origin size:" << data.size() << " after compressed size:" << out.size() << " compress status:" << status;
    ASSERT_TRUE(status);
    ASSERT_GT(out.size(), 0);

    std::string de_out;

    bool status2 = infra::Compressor::decompress(out, de_out, opts);

    LOG(INFO) << "origin size:" << out.size() << " after decompressed size:" << de_out.size() << " compress status:" << status2;
    ASSERT_TRUE(status2);
    ASSERT_GT(out.size(), 0);
}

TEST(compress, compressgzip) {
    std::string out;

    infra::CompressOptions opts{infra::Type::GZIP, 5};

    bool status = infra::Compressor::compress(data, out, opts);
    LOG(INFO) << "origin size:" << data.size() << " after compressed size:" << out.size() << " compress status:" << status;
    ASSERT_TRUE(status);
    ASSERT_GT(out.size(), 0);

    std::string de_out;

    bool status2 = infra::Compressor::decompress(out, de_out, opts);

    LOG(INFO) << "origin size:" << out.size() << " after decompressed size:" << de_out.size() << " compress status:" << status2;
    ASSERT_TRUE(status2);
    ASSERT_GT(out.size(), 0);
}

} // namespace tests