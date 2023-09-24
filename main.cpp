#include <folly/ScopeGuard.h>
#include <folly/system/Pid.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

auto main(int argc, char ** argv) -> int {
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);
    testing::InitGoogleTest(&argc, argv);
    FLAGS_stderrthreshold = google::GLOG_INFO;

    auto guard = folly::makeGuard([]() {
        LOG(WARNING) << "shutdown...";
        google::ShutdownGoogleLogging();
    });

    LOG(INFO) << "start. pid is: " << folly::get_cached_pid();

    return RUN_ALL_TESTS();
}