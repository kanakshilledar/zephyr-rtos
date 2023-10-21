/*
 * Copyright (c) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>

void test_main(void)
{
	ztest_run_test_suite(timer_jitter_drift);
<<<<<<< HEAD
	ztest_run_test_suite(timer_tick_train);
=======
#ifndef CONFIG_TIMER_EXTERNAL_TEST
	ztest_run_test_suite(timer_tick_train);
#endif
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}
