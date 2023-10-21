/*
 * Copyright (c) 2020 Friedt Professional Engineering Services, Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "_main.h"

<<<<<<< HEAD
ZTEST_USER(net_socketpair, test_write_nonblock)
{
	int res;
	int sv[2] = {-1, -1};

	res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
	zassert_equal(res, 0, "socketpair() failed: %d", errno);
=======
ZTEST_USER_F(net_socketpair, test_write_nonblock)
{
	int res;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	for (size_t i = 0; i < 2; ++i) {
		/* first, fill up the buffer */
		for (size_t k = 0; k < CONFIG_NET_SOCKETPAIR_BUFFER_SIZE;
			++k) {
<<<<<<< HEAD
			res = send(sv[i], "x", 1, 0);
=======
			res = send(fixture->sv[i], "x", 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			zassert_equal(res, 1, "send() failed: %d", errno);
		}

		/* then set the O_NONBLOCK flag */
<<<<<<< HEAD
		res = fcntl(sv[i], F_GETFL, 0);
		zassert_not_equal(res, -1, "fcntl() failed: %d", i, errno);

		res = fcntl(sv[i], F_SETFL, res | O_NONBLOCK);
		zassert_not_equal(res, -1, "fcntl() failed: %d", i, errno);

		/* then, try to write one more byte */
		res = send(sv[i], "x", 1, 0);
=======
		res = fcntl(fixture->sv[i], F_GETFL, 0);
		zassert_not_equal(res, -1, "fcntl() failed: %d", i, errno);

		res = fcntl(fixture->sv[i], F_SETFL, res | O_NONBLOCK);
		zassert_not_equal(res, -1, "fcntl() failed: %d", i, errno);

		/* then, try to write one more byte */
		res = send(fixture->sv[i], "x", 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, -1, "expected send to fail");
		zassert_equal(errno, EAGAIN, "errno: expected: EAGAIN "
			"actual: %d", errno);
	}
<<<<<<< HEAD

	close(sv[0]);
	close(sv[1]);
}

ZTEST_USER(net_socketpair, test_read_nonblock)
{
	int res;
	int sv[2] = {-1, -1};
	char c;

	res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
	zassert_equal(res, 0, "socketpair() failed: %d", errno);

	for (size_t i = 0; i < 2; ++i) {
		/* set the O_NONBLOCK flag */
		res = fcntl(sv[i], F_GETFL, 0);
		zassert_not_equal(res, -1, "fcntl() failed: %d", i, errno);

		res = fcntl(sv[i], F_SETFL, res | O_NONBLOCK);
		zassert_not_equal(res, -1, "fcntl() failed: %d", i, errno);

		/* then, try to read one byte */
		res = recv(sv[i], &c, 1, 0);
=======
}

ZTEST_USER_F(net_socketpair, test_read_nonblock)
{
	int res;
	char c;

	for (size_t i = 0; i < 2; ++i) {
		/* set the O_NONBLOCK flag */
		res = fcntl(fixture->sv[i], F_GETFL, 0);
		zassert_not_equal(res, -1, "fcntl() failed: %d", i, errno);

		res = fcntl(fixture->sv[i], F_SETFL, res | O_NONBLOCK);
		zassert_not_equal(res, -1, "fcntl() failed: %d", i, errno);

		/* then, try to read one byte */
		res = recv(fixture->sv[i], &c, 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, -1, "expected recv() to fail");
		zassert_equal(errno, EAGAIN, "errno: expected: EAGAIN "
			"actual: %d", errno);
	}
<<<<<<< HEAD

	close(sv[0]);
	close(sv[1]);
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}
