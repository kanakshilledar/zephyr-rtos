/*
 * Copyright (c) 2022 Jeppe Odgaard
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/sys_heap.h>

#define HEAP_SIZE	256

static char heap_mem[HEAP_SIZE];
static struct sys_heap heap;

<<<<<<< HEAD
void print_sys_memory_stats(void);
=======
static void print_sys_memory_stats(void);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

int main(void)
{
	void *p;

	printk("System heap sample\n\n");

	sys_heap_init(&heap, heap_mem, HEAP_SIZE);
	print_sys_memory_stats();

	p = sys_heap_alloc(&heap, 150);
	print_sys_memory_stats();

	p = sys_heap_realloc(&heap, p, 100);
	print_sys_memory_stats();

	sys_heap_free(&heap, p);
	print_sys_memory_stats();
	return 0;
}

<<<<<<< HEAD
void print_sys_memory_stats(void)
=======
static void print_sys_memory_stats(void)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	struct sys_memory_stats stats;

	sys_heap_runtime_stats_get(&heap, &stats);

	printk("allocated %zu, free %zu, max allocated %zu, heap size %u\n",
		stats.allocated_bytes, stats.free_bytes,
		stats.max_allocated_bytes, HEAP_SIZE);
}
