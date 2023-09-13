//
// Created by 韦轩 on 2023/7/16.
//

#include "sockets.h"

#include <cstdlib>
#include <glog/logging.h>
#include <gtest/gtest.h>

#define ERROR_EXIT(m, c) \
    do { \
        perror(m); \
        exit(c); \
    } while (false)

int socket_pair() {
    int sockfds[2];

    if (int status = socketpair(PF_UNIX, SOCK_STREAM, 0, sockfds); status < 0) {
        do {
            perror("socketpair");
        } while (false);
    }

    LOG(INFO) << "fd0:" << sockfds[0] << " fd1:" << sockfds[1];

    return 0;
}

namespace tests {

TEST(testsp, testsp) {
    socket_pair();
}
} // namespace tests