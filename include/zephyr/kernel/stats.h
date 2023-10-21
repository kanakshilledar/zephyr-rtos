/*
 * Copyright (c) 2021,2023, Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_KERNEL_STATS_H_
#define ZEPHYR_INCLUDE_KERNEL_STATS_H_

#include <stdint.h>
#include <stdbool.h>

<<<<<<< HEAD
/*
 * [k_cycle_stats] is used to track internal statistics about both thread
=======
/**
 * Structure used to track internal statistics about both thread
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 * and CPU usage.
 */

struct k_cycle_stats {
<<<<<<< HEAD
	uint64_t  total;        /* total usage in cycles */
#ifdef CONFIG_SCHED_THREAD_USAGE_ANALYSIS
	uint64_t  current;      /* # of cycles in current usage window */
	uint64_t  longest;      /* # of cycles in longest usage window */
	uint32_t  num_windows;  /* # of usage windows */
#endif
	bool      track_usage;  /* true if gathering usage stats */
=======
	uint64_t  total;        /**< total usage in cycles */
#if defined(CONFIG_SCHED_THREAD_USAGE_ANALYSIS) || defined(__DOXYGEN__)
	/**
	 * @name Fields available when CONFIG_SCHED_THREAD_USAGE_ANALYSIS is selected.
	 * @{
	 */
	uint64_t  current;      /**< \# of cycles in current usage window */
	uint64_t  longest;      /**< \# of cycles in longest usage window */
	uint32_t  num_windows;  /**< \# of usage windows */
	/** @} */
#endif
	bool      track_usage;  /**< true if gathering usage stats */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
};

#endif
