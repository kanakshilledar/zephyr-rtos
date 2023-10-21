/*
 * Copyright (c) 2023 Codecoup
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdlib.h>
#include <zephyr/kernel.h>

int k_mem_slab_alloc(struct k_mem_slab *slab, void **mem, k_timeout_t timeout)
{
<<<<<<< HEAD
	if (slab->num_used >= slab->num_blocks) {
=======
	if (slab->info.num_used >= slab->info.num_blocks) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		*mem = NULL;
		return -ENOMEM;
	}

<<<<<<< HEAD
	*mem = malloc(slab->block_size);
	zassert_not_null(*mem);

	slab->num_used++;
	return 0;
}

void k_mem_slab_free(struct k_mem_slab *slab, void **mem)
{
	free(*mem);
	slab->num_used--;
=======
	*mem = malloc(slab->info.block_size);
	zassert_not_null(*mem);

	slab->info.num_used++;
	return 0;
}

void k_mem_slab_free(struct k_mem_slab *slab, void *mem)
{
	free(mem);
	slab->info.num_used--;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}
