/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/timing/timing.h>
#include "utils.h"

#define TEST_COUNT 100
#define TEST_SIZE 10

void heap_malloc_free(void)
{
	timing_t heap_malloc_start_time = 0U;
	timing_t heap_malloc_end_time = 0U;

	timing_t heap_free_start_time = 0U;
	timing_t heap_free_end_time = 0U;

	uint32_t count = 0U;
	uint32_t sum_malloc = 0U;
	uint32_t sum_free = 0U;

<<<<<<< HEAD
=======
	bool  failed = false;
	char  error_string[80];
	const char *notes = "";

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	timing_start();

	while (count != TEST_COUNT) {
		heap_malloc_start_time = timing_counter_get();
		void *allocated_mem = k_malloc(TEST_SIZE);

		heap_malloc_end_time = timing_counter_get();
		if (allocated_mem == NULL) {
<<<<<<< HEAD
			printk("Failed to alloc memory from heap "
					"at count %d\n", count);
=======
			error_count++;
			snprintk(error_string, 78,
				  "alloc memory @ iteration %d", count);
			notes = error_string;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			break;
		}

		heap_free_start_time = timing_counter_get();
		k_free(allocated_mem);
		heap_free_end_time = timing_counter_get();

		sum_malloc += timing_cycles_get(&heap_malloc_start_time,
				&heap_malloc_end_time);
		sum_free += timing_cycles_get(&heap_free_start_time,
				&heap_free_end_time);
		count++;
	}

<<<<<<< HEAD
	/* if count is 0, it means that there is not enough memory heap
	 * to do k_malloc at least once, then it's meaningless to
	 * calculate average time of memory allocation and free.
	 */
	if (count == 0) {
		printk("Error: there isn't enough memory heap to do "
				"k_malloc at least once, please "
				"increase heap size\n");
	} else {
		PRINT_STATS_AVG("Average time for heap malloc", sum_malloc, count);
		PRINT_STATS_AVG("Average time for heap free", sum_free, count);
	}

=======
	/*
	 * If count is 0, it means that there is not enough memory heap
	 * to do k_malloc at least once. Override the error string.
	 */

	if (count == 0) {
		failed = true;
		notes = "Memory heap too small--increase it.";
	}

	PRINT_STATS_AVG("Average time for heap malloc", sum_malloc, count,
			failed, notes);
	PRINT_STATS_AVG("Average time for heap free", sum_free, count,
			failed, notes);

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	timing_stop();
}
