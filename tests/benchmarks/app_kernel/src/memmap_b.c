/* memmap_b.c */

/*
 * Copyright (c) 1997-2010, 2013-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "master.h"
#include <zephyr/kernel.h>

#ifdef MEMMAP_BENCH


/**
 *
 * @brief Memory map get/free test
 *
 */
void memorymap_test(void)
{
	uint32_t et; /* elapsed time */
	int i;
	void *p;
	int alloc_status;

<<<<<<< HEAD
	PRINT_STRING(dashline, output_file);
=======
	PRINT_STRING(dashline);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	et = BENCH_START();
	for (i = 0; i < NR_OF_MAP_RUNS; i++) {
		alloc_status = k_mem_slab_alloc(&MAP1, &p, K_FOREVER);
		if (alloc_status != 0) {
<<<<<<< HEAD
			PRINT_F(output_file, FORMAT,
				"Error: Slab allocation failed.", alloc_status);
			break;
		}
		k_mem_slab_free(&MAP1, &p);
=======
			PRINT_F(FORMAT,
				"Error: Slab allocation failed.", alloc_status);
			break;
		}
		k_mem_slab_free(&MAP1, p);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}
	et = TIME_STAMP_DELTA_GET(et);
	check_result();

<<<<<<< HEAD
	PRINT_F(output_file, FORMAT, "average alloc and dealloc memory page",
=======
	PRINT_F(FORMAT, "average alloc and dealloc memory page",
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		SYS_CLOCK_HW_CYCLES_TO_NS_AVG(et, (2 * NR_OF_MAP_RUNS)));
}

#endif /* MEMMAP_BENCH */
