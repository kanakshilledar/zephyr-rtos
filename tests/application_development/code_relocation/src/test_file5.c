/*
 * Copyright (c) 2022, NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/ztest.h>

__in_section(data, sram2, var) uint32_t var_file5_sram2_data = 10U;
__in_section(bss, sram2, var) uint32_t var_file5_sram2_bss;

ZTEST(code_relocation, test_function_genex_relocate_2)
{
<<<<<<< HEAD
	extern uintptr_t __sram2_data_start;
	extern uintptr_t __sram2_data_end;
	extern uintptr_t __sram2_bss_start;
	extern uintptr_t __sram2_bss_end;
=======
	extern uintptr_t __sram2_data_reloc_start;
	extern uintptr_t __sram2_data_reloc_end;
	extern uintptr_t __sram2_bss_reloc_start;
	extern uintptr_t __sram2_bss_reloc_end;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	printk("Address of var_file5_sram2_data %p\n", &var_file5_sram2_data);
	printk("Address of var_file5_sram2_bss %p\n\n", &var_file5_sram2_bss);

	zassert_between_inclusive((uintptr_t)&var_file5_sram2_data,
<<<<<<< HEAD
		(uintptr_t)&__sram2_data_start,
		(uintptr_t)&__sram2_data_end,
		"var_file5_sram2_data not in sram2_data region");
	zassert_between_inclusive((uintptr_t)&var_file5_sram2_bss,
		(uintptr_t)&__sram2_bss_start,
		(uintptr_t)&__sram2_bss_end,
=======
		(uintptr_t)&__sram2_data_reloc_start,
		(uintptr_t)&__sram2_data_reloc_end,
		"var_file5_sram2_data not in sram2_data region");
	zassert_between_inclusive((uintptr_t)&var_file5_sram2_bss,
		(uintptr_t)&__sram2_bss_reloc_start,
		(uintptr_t)&__sram2_bss_reloc_end,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		"var_file5_sram2_bss not in sram2_bss region");
}
