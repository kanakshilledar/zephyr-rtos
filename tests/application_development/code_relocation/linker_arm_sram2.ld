/*
 * Copyright (c) 2013-2014 Wind River Systems, Inc.
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

/** enable CONFIG_SRAM2 or any other partition in soc Kconfig,
 * this is just an example to show relocation of code/data/bss script
 */
#if defined CONFIG_ARM
  #define CONFIG_SRAM2 1
  #define _SRAM2_DATA_SECTION_NAME  .sram2_data
  #define _SRAM2_BSS_SECTION_NAME   .sram2_bss
  #define _SRAM2_TEXT_SECTION_NAME  .sram2_text
  #define SRAM2_ADDR  (CONFIG_SRAM_BASE_ADDRESS + RAM_SIZE2)
#endif

#define RAM_SIZE2 (CONFIG_SRAM_SIZE * 512)
MEMORY
    {
#ifdef CONFIG_SRAM2
    SRAM2                  (wx) : ORIGIN = (CONFIG_SRAM_BASE_ADDRESS + RAM_SIZE2), LENGTH = RAM_SIZE2
#endif
    }

<<<<<<< HEAD
#include <zephyr/arch/arm/aarch32/cortex_m/scripts/linker.ld>
=======
/* Include the SoC-specific linker file */
#include <linker.ld>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
