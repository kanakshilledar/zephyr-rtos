/*
 * Copyright (c) 2020 Friedt Professional Engineering Services, Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "_main.h"

struct ctx {
	bool should_write;
<<<<<<< HEAD
	int fd;
=======
	int *fd;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	k_timeout_t delay;
};
static ZTEST_BMEM struct ctx ctx;
static ZTEST_BMEM struct k_work work;

/*
 * Timeout should work the same for blocking & non-blocking threads
 *
 *   - no bytes available to read after timeout, r: 0 (timeout)
 *   - no bytes available to write after timeout, r: 0 (timeout)
 */

<<<<<<< HEAD
static void test_socketpair_poll_timeout_common(int sv[2])
{
	int res;

	struct pollfd fds[1];

	memset(fds, 0, sizeof(fds));
	fds[0].fd = sv[0];
=======
static void test_socketpair_poll_timeout_common(struct net_socketpair_fixture *fixture)
{
	int res;
	struct pollfd fds[1];

	memset(fds, 0, sizeof(fds));
	fds[0].fd = fixture->sv[0];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	fds[0].events |= POLLIN;
	res = poll(fds, 1, 1);
	zassert_equal(res, 0, "poll: expected: 0 actual: %d", res);

	for (size_t i = 0; i < CONFIG_NET_SOCKETPAIR_BUFFER_SIZE; ++i) {
<<<<<<< HEAD
		res = send(sv[0], "x", 1, 0);
=======
		res = send(fixture->sv[0], "x", 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, 1, "send() failed: %d", res);
	}

	memset(fds, 0, sizeof(fds));
<<<<<<< HEAD
	fds[0].fd = sv[0];
	fds[0].events |= POLLOUT;
	res = poll(fds, 1, 1);
	zassert_equal(res, 0, "poll: expected: 0 actual: %d", res);

	close(sv[0]);
	close(sv[1]);
}

ZTEST_USER(net_socketpair, test_poll_timeout)
{
	int sv[2] = {-1, -1};
	int res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);

	zassert_not_equal(res, -1, "socketpair failed: %d", errno);

	test_socketpair_poll_timeout_common(sv);
}

/* O_NONBLOCK should have no affect on poll(2) */
ZTEST_USER(net_socketpair, test_poll_timeout_nonblocking)
{
	int sv[2] = {-1, -1};
	int res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);

	zassert_not_equal(res, -1, "socketpair failed: %d", errno);

	res = fcntl(sv[0], F_GETFL, 0);
=======
	fds[0].fd = fixture->sv[0];
	fds[0].events |= POLLOUT;
	res = poll(fds, 1, 1);
	zassert_equal(res, 0, "poll: expected: 0 actual: %d", res);
}

ZTEST_USER_F(net_socketpair, test_poll_timeout)
{
	test_socketpair_poll_timeout_common(fixture);
}

/* O_NONBLOCK should have no affect on poll(2) */
ZTEST_USER_F(net_socketpair, test_poll_timeout_nonblocking)
{
	int res;

	res = fcntl(fixture->sv[0], F_GETFL, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	zassert_not_equal(res, -1, "fcntl failed: %d", errno);

	int flags = res;

<<<<<<< HEAD
	res = fcntl(sv[0], F_SETFL, O_NONBLOCK | flags);
	zassert_not_equal(res, -1, "fcntl failed: %d", errno);

	res = fcntl(sv[1], F_SETFL, O_NONBLOCK | flags);
	zassert_not_equal(res, -1, "fcntl failed: %d", errno);

	test_socketpair_poll_timeout_common(sv);
}

static void close_fun(struct k_work *work)
{
	(void)work;
=======
	res = fcntl(fixture->sv[0], F_SETFL, O_NONBLOCK | flags);
	zassert_not_equal(res, -1, "fcntl failed: %d", errno);

	res = fcntl(fixture->sv[1], F_SETFL, O_NONBLOCK | flags);
	zassert_not_equal(res, -1, "fcntl failed: %d", errno);

	test_socketpair_poll_timeout_common(fixture);
}

static void close_fun(struct k_work *w)
{
	(void)w;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	if (!(K_TIMEOUT_EQ(ctx.delay, K_NO_WAIT)
		|| K_TIMEOUT_EQ(ctx.delay, K_FOREVER))) {
		k_sleep(ctx.delay);
	}

<<<<<<< HEAD
	LOG_DBG("about to close fd %d", ctx.fd);
	close(ctx.fd);
=======
	LOG_DBG("about to close fd %d", *ctx.fd);
	close(*ctx.fd);
	*ctx.fd = -1;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

/*
 * Hangup should cause the following behaviour
 *   - close remote fd while the local fd is blocking in poll. r: 1,
 *     POLLIN, read -> r: 0, errno: 0 -> EOF
 *   - close remote fd while the local fd is blocking in poll. r: 1,
 *     POLLOUT, write -> r: -1, errno: EPIPE.
 */
<<<<<<< HEAD
ZTEST(net_socketpair, test_poll_close_remote_end_POLLIN)
=======
ZTEST_F(net_socketpair, test_poll_close_remote_end_POLLIN)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	int res;
	char c;
	struct pollfd fds[1];

<<<<<<< HEAD
	int sv[2] = {-1, -1};

	res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
	zassert_not_equal(res, -1, "socketpair() failed: %d", errno);

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	/*
	 * poll until there are bytes to read.
	 * But rather than writing, close the other end of the channel
	 */

	memset(fds, 0, sizeof(fds));
<<<<<<< HEAD
	fds[0].fd = sv[0];
	fds[0].events |= POLLIN;

	memset(&ctx, 0, sizeof(ctx));
	ctx.fd = sv[1];
=======
	fds[0].fd = fixture->sv[0];
	fds[0].events |= POLLIN;

	memset(&ctx, 0, sizeof(ctx));
	ctx.fd = &fixture->sv[1];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	ctx.delay = K_MSEC(1000);

	LOG_DBG("scheduling work");
	k_work_init(&work, close_fun);
	k_work_submit(&work);

	res = poll(fds, 1, -1);
	zassert_equal(res, 1, "poll() failed: %d", res);
	zassert_equal(fds[0].revents & POLLIN, POLLIN, "POLLIN not set");

<<<<<<< HEAD
	res = recv(sv[0], &c, 1, 0);
	zassert_equal(res, 0, "read did not return EOF");

	close(sv[0]);
}

ZTEST(net_socketpair, test_poll_close_remote_end_POLLOUT)
=======
	res = recv(fixture->sv[0], &c, 1, 0);
	zassert_equal(res, 0, "read did not return EOF");
}

ZTEST_F(net_socketpair, test_poll_close_remote_end_POLLOUT)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	int res;
	struct pollfd fds[1];

<<<<<<< HEAD
	int sv[2] = {-1, -1};

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	/*
	 * Fill up the remote q and then poll until write space is available.
	 * But rather than reading, close the other end of the channel
	 */

<<<<<<< HEAD
	res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
	zassert_not_equal(res, -1, "socketpair() failed: %d", errno);

	for (size_t i = 0; i < CONFIG_NET_SOCKETPAIR_BUFFER_SIZE; ++i) {
		res = send(sv[0], "x", 1, 0);
=======
	res = socketpair(AF_UNIX, SOCK_STREAM, 0, fixture->sv);
	zassert_not_equal(res, -1, "socketpair() failed: %d", errno);

	for (size_t i = 0; i < CONFIG_NET_SOCKETPAIR_BUFFER_SIZE; ++i) {
		res = send(fixture->sv[0], "x", 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, 1, "send failed: %d", res);
	}

	memset(fds, 0, sizeof(fds));
<<<<<<< HEAD
	fds[0].fd = sv[0];
	fds[0].events |= POLLOUT;

	memset(&ctx, 0, sizeof(ctx));
	ctx.fd = sv[1];
=======
	fds[0].fd = fixture->sv[0];
	fds[0].events |= POLLOUT;

	memset(&ctx, 0, sizeof(ctx));
	ctx.fd = &fixture->sv[1];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	ctx.delay = K_MSEC(1000);

	LOG_DBG("scheduling work");
	k_work_init(&work, close_fun);
	k_work_submit(&work);

	res = poll(fds, 1, -1);
	zassert_equal(res, 1, "poll() failed: %d", res);
	zassert_equal(fds[0].revents & POLLHUP, POLLHUP, "POLLHUP not set");

<<<<<<< HEAD
	res = send(sv[0], "x", 1, 0);
	zassert_equal(res, -1, "send(): expected: -1 actual: %d", res);
	zassert_equal(errno, EPIPE, "errno: expected: EPIPE actual: %d", errno);

	close(sv[0]);
=======
	res = send(fixture->sv[0], "x", 1, 0);
	zassert_equal(res, -1, "send(): expected: -1 actual: %d", res);
	zassert_equal(errno, EPIPE, "errno: expected: EPIPE actual: %d", errno);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

/*
 * Data available immediately
 *   - even with a timeout value of 0 us, poll should return immediately with
 *     a value of 1 (for either read or write cases)
 *   - even with a timeout value of 0us, poll should return immediately with
 *     a value of 2 if both read and write are available
 */
<<<<<<< HEAD
ZTEST_USER(net_socketpair, test_poll_immediate_data)
{
	int sv[2] = {-1, -1};
	int res;

	struct pollfd fds[2];

	res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
	zassert_not_equal(res, -1, "socketpair() failed: %d", errno);

	memset(fds, 0, sizeof(fds));
	fds[0].fd = sv[0];
=======
ZTEST_USER_F(net_socketpair, test_poll_immediate_data)
{
	int res;
	struct pollfd fds[2];

	memset(fds, 0, sizeof(fds));
	fds[0].fd = fixture->sv[0];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	fds[0].events |= POLLOUT;
	res = poll(fds, 1, 0);
	zassert_not_equal(res, -1, "poll() failed: %d", errno);
	zassert_equal(res, 1, "poll(): expected: 1 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLOUT, 0, "POLLOUT not set");

<<<<<<< HEAD
	res = send(sv[0], "x", 1, 0);
=======
	res = send(fixture->sv[0], "x", 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	zassert_not_equal(res, -1, "send() failed: %d", errno);
	zassert_equal(res, 1, "write(): expected: 1 actual: %d", res);

	memset(fds, 0, sizeof(fds));
<<<<<<< HEAD
	fds[0].fd = sv[1];
=======
	fds[0].fd = fixture->sv[1];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	fds[0].events |= POLLIN;
	res = poll(fds, 1, 0);
	zassert_not_equal(res, -1, "poll() failed: %d", errno);
	zassert_equal(res, 1, "poll(): expected: 1 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLIN, 0, "POLLIN not set");

	memset(fds, 0, sizeof(fds));
<<<<<<< HEAD
	fds[0].fd = sv[0];
	fds[0].events |= POLLOUT;
	fds[1].fd = sv[1];
=======
	fds[0].fd = fixture->sv[0];
	fds[0].events |= POLLOUT;
	fds[1].fd = fixture->sv[1];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	fds[1].events |= POLLIN;
	res = poll(fds, 2, 0);
	zassert_not_equal(res, -1, "poll() failed: %d", errno);
	zassert_equal(res, 2, "poll(): expected: 1 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLOUT, 0, "POLLOUT not set");
	zassert_not_equal(fds[1].revents & POLLIN, 0, "POLLIN not set");
<<<<<<< HEAD

	close(sv[0]);
	close(sv[1]);
}

static void rw_fun(struct k_work *work)
{
	(void)work;
=======
}

static void rw_fun(struct k_work *w)
{
	(void)w;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	int res;
	char c;

	if (!(K_TIMEOUT_EQ(ctx.delay, K_NO_WAIT)
		|| K_TIMEOUT_EQ(ctx.delay, K_FOREVER))) {
		k_sleep(ctx.delay);
	}

	if (ctx.should_write) {
		LOG_DBG("about to write 1 byte");
<<<<<<< HEAD
		res = send(ctx.fd, "x", 1, 0);
=======
		res = send(*ctx.fd, "x", 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		if (-1 == res) {
			LOG_DBG("send() failed: %d", errno);
		} else {
			LOG_DBG("wrote 1 byte");
		}
	} else {
		LOG_DBG("about to read 1 byte");
<<<<<<< HEAD
		res = recv(ctx.fd, &c, 1, 0);
=======
		res = recv(*ctx.fd, &c, 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		if (-1 == res) {
			LOG_DBG("recv() failed: %d", errno);
		} else {
			LOG_DBG("read 1 byte");
		}
	}
}

/*
 * Data only available but after some short period
 *   - say there is a timeout value of 5 s, poll should return immediately
 *     with the a value of 1 (for either read or write cases)
 */
<<<<<<< HEAD
ZTEST(net_socketpair, test_poll_delayed_data)
{
	int sv[2] = {-1, -1};
	int res;

	struct pollfd fds[1];

	res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
	zassert_not_equal(res, -1, "socketpair() failed: %d", errno);

	memset(fds, 0, sizeof(fds));
	fds[0].fd = sv[0];
	fds[0].events |= POLLIN;

	memset(&ctx, 0, sizeof(ctx));
	ctx.fd = sv[1];
=======
ZTEST_F(net_socketpair, test_poll_delayed_data)
{
	int res;
	struct pollfd fds[1];

	memset(fds, 0, sizeof(fds));
	fds[0].fd = fixture->sv[0];
	fds[0].events |= POLLIN;

	memset(&ctx, 0, sizeof(ctx));
	ctx.fd = &fixture->sv[1];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	ctx.should_write = true;
	ctx.delay = K_MSEC(100);

	LOG_DBG("scheduling work");
	k_work_init(&work, rw_fun);
	k_work_submit(&work);

	res = poll(fds, 1, 5000);
	zassert_not_equal(res, -1, "poll() failed: %d", errno);
	zassert_equal(res, 1, "poll(): expected: 1 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLIN, 0, "POLLIN not set");

	for (size_t i = 0; i < CONFIG_NET_SOCKETPAIR_BUFFER_SIZE; ++i) {
<<<<<<< HEAD
		res = send(sv[0], "x", 1, 0);
=======
		res = send(fixture->sv[0], "x", 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, 1, "send() failed: %d", res);
	}

	memset(fds, 0, sizeof(fds));
<<<<<<< HEAD
	fds[0].fd = sv[0];
	fds[0].events |= POLLOUT;

	memset(&ctx, 0, sizeof(ctx));
	ctx.fd = sv[1];
=======
	fds[0].fd = fixture->sv[0];
	fds[0].events |= POLLOUT;

	memset(&ctx, 0, sizeof(ctx));
	ctx.fd = &fixture->sv[1];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	ctx.should_write = false;
	ctx.delay = K_MSEC(100);

	LOG_DBG("scheduling work");
	k_work_init(&work, rw_fun);
	k_work_submit(&work);

	res = poll(fds, 1, 5000);
	zassert_not_equal(res, -1, "poll() failed: %d", errno);
	zassert_equal(res, 1, "poll(): expected: 1 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLOUT, 0, "POLLOUT was not set");
<<<<<<< HEAD

	close(sv[0]);
	close(sv[1]);
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

/*
 * Verify that POLLIN is correctly signalled
 *   - right after socket creation, POLLIN should not be reported
 *   - after data is written to a remote socket, POLLIN should be reported, even
 *     if the poll was called after the data was written
 *   - after reading data from a remote socket, POLLIN shouldn't be reported
 */
<<<<<<< HEAD
ZTEST_USER(net_socketpair, test_poll_signalling_POLLIN)
{
	int sv[2] = {-1, -1};
	int res;
	char c;
	int64_t timestamp, delta;

	struct pollfd fds[1];

	res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
	zassert_not_equal(res, -1, "socketpair failed: %d", errno);

	memset(fds, 0, sizeof(fds));
	fds[0].fd = sv[1];
=======
ZTEST_USER_F(net_socketpair, test_poll_signalling_POLLIN)
{
	int res;
	char c;
	int64_t timestamp, delta;
	struct pollfd fds[1];

	memset(fds, 0, sizeof(fds));
	fds[0].fd = fixture->sv[1];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	fds[0].events |= POLLIN;
	res = poll(fds, 1, 0);
	zassert_not_equal(res, -1, "poll failed: %d", errno);
	zassert_equal(res, 0, "poll: expected: 0 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLIN, POLLIN, "POLLIN set");

<<<<<<< HEAD
	res = send(sv[0], "x", 1, 0);
=======
	res = send(fixture->sv[0], "x", 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	zassert_equal(res, 1, "send failed: %d", res);

	timestamp = k_uptime_get();

	memset(fds, 0, sizeof(fds));
<<<<<<< HEAD
	fds[0].fd = sv[1];
=======
	fds[0].fd = fixture->sv[1];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	fds[0].events |= POLLIN;
	res = poll(fds, 1, 1000);
	zassert_not_equal(res, -1, "poll failed: %d", errno);
	zassert_equal(res, 1, "poll: expected: 1 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLIN, 0, "POLLIN not set");

	delta = k_uptime_delta(&timestamp);
	zassert_true(delta < 100, "poll did not exit immediately");

<<<<<<< HEAD
	res = recv(sv[1], &c, 1, 0);
	zassert_equal(res, 1, "recv failed: %d", res);

	memset(fds, 0, sizeof(fds));
	fds[0].fd = sv[1];
=======
	res = recv(fixture->sv[1], &c, 1, 0);
	zassert_equal(res, 1, "recv failed: %d", res);

	memset(fds, 0, sizeof(fds));
	fds[0].fd = fixture->sv[1];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	fds[0].events |= POLLIN;
	res = poll(fds, 1, 0);
	zassert_not_equal(res, -1, "poll failed: %d", errno);
	zassert_equal(res, 0, "poll: expected: 0 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLIN, POLLIN, "POLLIN set");
<<<<<<< HEAD

	close(sv[0]);
	close(sv[1]);
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

/*
 * Verify that POLLOUT is correctly signalled
 *   - right after socket creation, POLLOUT should be reported
 *   - after remote buffer is filled up, POLLOUT shouldn't be reported
 *   - after reading data from a remote socket, POLLOUT should be reported
 *     again
 */
<<<<<<< HEAD
ZTEST_USER(net_socketpair, test_poll_signalling_POLLOUT)
{
	int sv[2] = {-1, -1};
	int res;
	char c;
	int64_t timestamp, delta;

	struct pollfd fds[1];

	res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
	zassert_not_equal(res, -1, "socketpair failed: %d", errno);

	timestamp = k_uptime_get();

	memset(fds, 0, sizeof(fds));
	fds[0].fd = sv[0];
=======
ZTEST_USER_F(net_socketpair, test_poll_signalling_POLLOUT)
{
	int res;
	char c;
	int64_t timestamp, delta;
	struct pollfd fds[1];

	timestamp = k_uptime_get();

	memset(fds, 0, sizeof(fds));
	fds[0].fd = fixture->sv[0];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	fds[0].events |= POLLOUT;
	res = poll(fds, 1, 1000);
	zassert_not_equal(res, -1, "poll failed: %d", errno);
	zassert_equal(res, 1, "poll: expected: 1 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLOUT, 0, "POLLOUT not set");

	delta = k_uptime_delta(&timestamp);
	zassert_true(delta < 100, "poll did not exit immediately");

	/* Fill up the remote buffer */
	for (size_t i = 0; i < CONFIG_NET_SOCKETPAIR_BUFFER_SIZE; ++i) {
<<<<<<< HEAD
		res = send(sv[0], "x", 1, 0);
=======
		res = send(fixture->sv[0], "x", 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, 1, "send() failed: %d", res);
	}

	memset(fds, 0, sizeof(fds));
<<<<<<< HEAD
	fds[0].fd = sv[0];
=======
	fds[0].fd = fixture->sv[0];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	fds[0].events |= POLLOUT;
	res = poll(fds, 1, 0);
	zassert_not_equal(res, -1, "poll failed: %d", errno);
	zassert_equal(res, 0, "poll: expected: 0 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLOUT, POLLOUT, "POLLOUT is set");

<<<<<<< HEAD
	res = recv(sv[1], &c, 1, 0);
=======
	res = recv(fixture->sv[1], &c, 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	zassert_equal(res, 1, "recv() failed: %d", res);

	timestamp = k_uptime_get();

	memset(fds, 0, sizeof(fds));
<<<<<<< HEAD
	fds[0].fd = sv[0];
=======
	fds[0].fd = fixture->sv[0];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	fds[0].events |= POLLOUT;
	res = poll(fds, 1, 1000);
	zassert_not_equal(res, -1, "poll failed: %d", errno);
	zassert_equal(res, 1, "poll: expected: 1 actual: %d", res);
	zassert_not_equal(fds[0].revents & POLLOUT, 0, "POLLOUT not set");

	delta = k_uptime_delta(&timestamp);
	zassert_true(delta < 100, "poll did not exit immediately");
<<<<<<< HEAD

	close(sv[0]);
	close(sv[1]);
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}
