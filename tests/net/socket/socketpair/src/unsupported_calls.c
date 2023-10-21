/*
 * Copyright (c) 2020 Friedt Professional Engineering Services, Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "_main.h"

<<<<<<< HEAD
ZTEST_USER(net_socketpair, test_unsupported_calls)
{
	int res;
	int sv[2] = {-1, -1};
=======
ZTEST_USER_F(net_socketpair, test_unsupported_calls)
{
	int res;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	struct sockaddr_un addr = {
		.sun_family = AF_UNIX,
	};
	socklen_t len = sizeof(addr);

<<<<<<< HEAD
	res = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);
	zassert_equal(res, 0,
		"socketpair(AF_UNIX, SOCK_STREAM, 0, sv) failed");


	for (size_t i = 0; i < 2; ++i) {

		res = bind(sv[i], (struct sockaddr *)&addr, len);
=======
	for (size_t i = 0; i < 2; ++i) {

		res = bind(fixture->sv[i], (struct sockaddr *)&addr, len);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, -1,
			"bind should fail on a socketpair endpoint");
		zassert_equal(errno, EISCONN,
			"bind should set errno to EISCONN");

<<<<<<< HEAD
		res = connect(sv[i], (struct sockaddr *)&addr, len);
=======
		res = connect(fixture->sv[i], (struct sockaddr *)&addr, len);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, -1,
			"connect should fail on a socketpair endpoint");
		zassert_equal(errno, EISCONN,
			"connect should set errno to EISCONN");

<<<<<<< HEAD
		res = listen(sv[i], 1);
=======
		res = listen(fixture->sv[i], 1);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, -1,
			"listen should fail on a socketpair endpoint");
		zassert_equal(errno, EINVAL,
			"listen should set errno to EINVAL");

<<<<<<< HEAD
		res = accept(sv[i], (struct sockaddr *)&addr, &len);
=======
		res = accept(fixture->sv[i], (struct sockaddr *)&addr, &len);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		zassert_equal(res, -1,
			"accept should fail on a socketpair endpoint");
		zassert_equal(errno, EOPNOTSUPP,
			"accept should set errno to EOPNOTSUPP");
	}
<<<<<<< HEAD

	res = close(sv[0]);
	zassert_equal(res, 0, "close failed");

	res = close(sv[1]);
	zassert_equal(res, 0, "close failed");
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}
