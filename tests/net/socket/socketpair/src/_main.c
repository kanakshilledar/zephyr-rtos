/*
 * Copyright (c) 2020 Friedt Professional Engineering Services, Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

<<<<<<< HEAD
#include <zephyr/logging/log.h>
#include <zephyr/ztest.h>

LOG_MODULE_REGISTER(net_test, CONFIG_NET_SOCKETS_LOG_LEVEL);

static void *setup(void)
{
	k_thread_system_pool_assign(k_current_get());
	return NULL;
}

ZTEST_SUITE(net_socketpair, NULL, setup, NULL, NULL, NULL);
=======
#include "_main.h"

#include <zephyr/logging/log.h>
#include <zephyr/net/socket.h>
#include <zephyr/ztest.h>

static ZTEST_DMEM struct net_socketpair_fixture fixture;
static void *setup(void)
{
	k_thread_system_pool_assign(k_current_get());

	return &fixture;
}

static void before(void *arg)
{
	struct net_socketpair_fixture *fixture = arg;

	for (int i = 0; i < 2; ++i) {
		if (fixture->sv[i] >= 0) {
			fixture->sv[i] = -1;
		}
	}
	zassert_ok(socketpair(AF_UNIX, SOCK_STREAM, 0, fixture->sv));
}

static void after(void *arg)
{
	struct net_socketpair_fixture *fixture = arg;

	for (int i = 0; i < 2; ++i) {
		if (fixture->sv[i] >= 0) {
			zassert_ok(close(fixture->sv[i]));
			fixture->sv[i] = -1;
		}
	}
}

ZTEST_SUITE(net_socketpair, NULL, setup, before, after, NULL);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
