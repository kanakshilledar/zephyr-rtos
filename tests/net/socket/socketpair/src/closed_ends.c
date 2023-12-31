/* SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2020 Friedt Professional Engineering Services, Inc
 */

#include "_main.h"

<<<<<<< HEAD
ZTEST_USER(net_socketpair, test_close_one_end_and_write_to_the_other)
{
	int res;
	int sv[2] = {-1, -1};

	for (size_t i = 0; i < 2; ++i) {
		res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
		zassert_equal(res, 0, "socketpair() failed: %d", errno);

		res = close(sv[i]);
		zassert_equal(res, 0, "close(sv[%u]) failed: %d", i, errno);

		res = send(sv[(!i) & 1], "x", 1, 0);
=======
ZTEST_USER_F(net_socketpair, test_close_one_end_and_write_to_the_other)
{
	int res;

	for (size_t i = 0; i < 2; ++i) {
		res = close(fixture->sv[i]);
		zassert_equal(res, 0, "close(fixture->sv[%u]) failed: %d", i, errno);
		fixture->sv[i] = -1;

		res = send(fixture->sv[(!i) & 1], "x", 1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, -1, "expected send() to fail");
		zassert_equal(res, -1, "errno: expected: EPIPE actual: %d",
			errno);

<<<<<<< HEAD
		res = close(sv[(!i) & 1]);
		zassert_equal(res, 0, "close(sv[%u]) failed: %d", i, errno);
	}
}

ZTEST_USER(net_socketpair, test_close_one_end_and_read_from_the_other)
{
	int res;
	int sv[2] = {-1, -1};
	char xx[16];

	for (size_t i = 0; i < 2; ++i) {
		res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
		zassert_equal(res, 0, "socketpair() failed: %d", errno);

=======
		res = close(fixture->sv[(!i) & 1]);
		zassert_equal(res, 0, "close(fixture->sv[%u]) failed: %d", i, errno);
		fixture->sv[(!i) & 1] = -1;

		res = socketpair(AF_UNIX, SOCK_STREAM, 0, fixture->sv);
		zassert_equal(res, 0, "socketpair() failed: %d", errno);
	}
}

ZTEST_USER_F(net_socketpair, test_close_one_end_and_read_from_the_other)
{
	int res;
	char xx[16];

	for (size_t i = 0; i < 2; ++i) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		/* We want to write some bytes to the closing end of the
		 * socket before it gets shut down, so that we can prove that
		 * reading is possible from the other end still and that data
		 * is not lost.
		 */
<<<<<<< HEAD
		res = send(sv[i], "xx", 2, 0);
		zassert_not_equal(res, -1, "send() failed: %d", errno);
		zassert_equal(res, 2, "write() failed to write 2 bytes");

		res = close(sv[i]);
		zassert_equal(res, 0, "close(sv[%u]) failed: %d", i, errno);

		memset(xx, 0, sizeof(xx));
		res = recv(sv[(!i) & 1], xx, sizeof(xx), 0);
=======
		res = send(fixture->sv[i], "xx", 2, 0);
		zassert_not_equal(res, -1, "send() failed: %d", errno);
		zassert_equal(res, 2, "write() failed to write 2 bytes");

		res = close(fixture->sv[i]);
		zassert_equal(res, 0, "close(fixture->sv[%u]) failed: %d", i, errno);
		fixture->sv[i] = -1;

		memset(xx, 0, sizeof(xx));
		res = recv(fixture->sv[(!i) & 1], xx, sizeof(xx), 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_not_equal(res, -1, "read() failed: %d", errno);
		zassert_equal(res, 2, "expected to read 2 bytes but read %d",
			res);

<<<<<<< HEAD
		res = recv(sv[(!i) & 1], xx, sizeof(xx), 0);
		zassert_equal(res, 0, "expected read() to succeed but read 0 bytes");

		res = close(sv[(!i) & 1]);
		zassert_equal(res, 0, "close(sv[%u]) failed: %d", i, errno);
=======
		res = recv(fixture->sv[(!i) & 1], xx, sizeof(xx), 0);
		zassert_equal(res, 0, "expected read() to succeed but read 0 bytes");

		res = close(fixture->sv[(!i) & 1]);
		zassert_equal(res, 0, "close(fixture->sv[%u]) failed: %d", i, errno);
		fixture->sv[(!i) & 1] = -1;

		res = socketpair(AF_UNIX, SOCK_STREAM, 0, fixture->sv);
		zassert_equal(res, 0, "socketpair() failed: %d", errno);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}
}
