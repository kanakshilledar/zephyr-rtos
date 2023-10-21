/*
 * Copyright (c) 2020 Friedt Professional Engineering Services, Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef TEST_SOCKETPAIR_THREAD_H_
#define TEST_SOCKETPAIR_THREAD_H_

#include <errno.h>
#include <string.h>

#include <zephyr/logging/log.h>
#include <zephyr/net/socket.h>
#include <zephyr/posix/fcntl.h>
#include <zephyr/sys/util.h>
#include <zephyr/ztest.h>

LOG_MODULE_DECLARE(net_test, CONFIG_NET_SOCKETS_LOG_LEVEL);

<<<<<<< HEAD
extern struct k_work_q test_socketpair_work_q;
=======
struct net_socketpair_fixture {
	int sv[2];
};
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#endif /* TEST_SOCKETPAIR_THREAD_H_ */
