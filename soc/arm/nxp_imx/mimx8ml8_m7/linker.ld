/*
 * Copyright (c) 2021, Laird Connectivity
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#include <zephyr/devicetree.h>

MEMORY
     {
#if defined(CONFIG_CODE_DDR)
        DDR  (wx) : ORIGIN = 0x80400000, LENGTH = 0x00C00000
#else
        DDR  (wx) : ORIGIN = 0x80000000, LENGTH = 0x01000000
#endif
     }

<<<<<<< HEAD
#include <zephyr/arch/arm/aarch32/cortex_m/scripts/linker.ld>
=======
#include <zephyr/arch/arm/cortex_m/scripts/linker.ld>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

SECTIONS
     {
#ifdef CONFIG_OPENAMP_RSC_TABLE
        SECTION_PROLOGUE(.resource_table,, SUBALIGN(4))
        {
            KEEP(*(.resource_table*))
        } GROUP_LINK_IN(ROMABLE_REGION)
#endif
     }
