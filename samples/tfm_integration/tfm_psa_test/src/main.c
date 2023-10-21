/*
 * Copyright (c) 2021 Nordic Semiconductor ASA.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

/* Run the PSA test suite */
void psa_test(void);

<<<<<<< HEAD
__attribute__((noreturn))
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
int main(void)
{
#ifdef CONFIG_TFM_PSA_TEST_NONE
	#error "No PSA test suite set. Use Kconfig to enable a test suite.\n"
#else
	psa_test();
#endif

	for (;;) {
	}
}
