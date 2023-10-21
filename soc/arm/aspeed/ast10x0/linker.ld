/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2020 Linumiz
 */
MEMORY
{
	SRAM_NC (wx) : ORIGIN = CONFIG_SRAM_NC_BASE_ADDRESS, LENGTH = CONFIG_SRAM_NC_SIZE * 1024
}
<<<<<<< HEAD
#include <zephyr/arch/arm/aarch32/cortex_m/scripts/linker.ld>
=======
#include <zephyr/arch/arm/cortex_m/scripts/linker.ld>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
