//
// Created by 韦轩 on 2023/7/16.
//

#pragma once
#include <cerrno>
#include <cstdio>
#include <cstdlib>

#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>

int socket_pair();