/*
 * Copyright (c) 2022 Carlo Caione <ccaione@baylibre.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Linker command/script file
 *
 * Linker script for the Cortex-M platforms.
 */

#include <zephyr/linker/sections.h>
#include <zephyr/devicetree.h>

#include <zephyr/linker/linker-defs.h>
#include <zephyr/linker/linker-tool.h>

<<<<<<< HEAD
#if CONFIG_BOARD_NRF5340DK_NRF5340_CPUAPP

/*
 * nRF5340dk is shipping a QSPI external flash mapped at 0x1000_0000 that can
 * be used for XIP
 */
MEMORY
{
     EXTFLASH (wx) : ORIGIN = 0x10000000, LENGTH = 0x800000
}
=======
#if defined(CONFIG_NORDIC_QSPI_NOR) && defined(CONFIG_SOC_NRF5340_CPUAPP)

/* On nRF5340, external flash is mapped in XIP region at 0x1000_0000. */

#define EXTFLASH_NODE	DT_INST(0, nordic_qspi_nor)
#define EXTFLASH_ADDR	0x10000000
#define EXTFLASH_SIZE	DT_PROP_OR(EXTFLASH_NODE, size_in_bytes, \
				   DT_PROP(EXTFLASH_NODE, size) / 8)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#else

/*
 * Add another fake portion of FLASH to simulate a secondary or external FLASH
 * that we can do XIP from.
 */
#define EXTFLASH_ADDR	0x5000
#define EXTFLASH_SIZE	(CONFIG_FLASH_SIZE * 1K - EXTFLASH_ADDR)

<<<<<<< HEAD
MEMORY
{
     EXTFLASH (wx) : ORIGIN = 0x5000, LENGTH = EXTFLASH_SIZE
}

#endif /* CONFIG_BOARD_NRF5340DK_NRF5340_CPUAPP */

#include <zephyr/arch/arm/aarch32/cortex_m/scripts/linker.ld>
=======
#endif

MEMORY
{
	EXTFLASH (rx) : ORIGIN = EXTFLASH_ADDR, LENGTH = EXTFLASH_SIZE
}

#include <zephyr/arch/arm/cortex_m/scripts/linker.ld>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
