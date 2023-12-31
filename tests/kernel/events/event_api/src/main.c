/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @brief Tests for the events kernel object
 *
 * Verify zephyr event apis under different context
 *
 * - API coverage
 *   -# k_event_init K_EVENT_DEFINE
 *   -# k_event_post
 *   -# k_event_set
 *   -# k_event_wait
 *   -# k_event_wait_all
<<<<<<< HEAD
=======
 *   -# k_event_test
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 *
 * @defgroup kernel_event_tests events
 * @ingroup all_tests
 * @{
 * @}
 */

#include <zephyr/ztest.h>

ZTEST_SUITE(events_api, NULL, NULL,
		ztest_simple_1cpu_before, ztest_simple_1cpu_after, NULL);
