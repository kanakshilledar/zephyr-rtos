# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
zephyr_library()

zephyr_library_sources_ifdef(CONFIG_KSCAN_GT911  	kscan_gt911.c)
zephyr_library_sources_ifdef(CONFIG_KSCAN_ITE_IT8XXX2	kscan_ite_it8xxx2.c)
zephyr_library_sources_ifdef(CONFIG_KSCAN_XEC		kscan_mchp_xec.c)
zephyr_library_sources_ifdef(CONFIG_KSCAN_HT16K33	kscan_ht16k33.c)
zephyr_library_sources_ifdef(CONFIG_KSCAN_CST816S	kscan_cst816s.c)
zephyr_library_sources_ifdef(CONFIG_KSCAN_CAP1203	kscan_cap1203.c)
zephyr_library_sources_ifdef(CONFIG_KSCAN_XPT2046	kscan_xpt2046.c)
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/kscan.h)

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_KSCAN_ITE_IT8XXX2	kscan_ite_it8xxx2.c)
zephyr_library_sources_ifdef(CONFIG_KSCAN_XEC		kscan_mchp_xec.c)
zephyr_library_sources_ifdef(CONFIG_KSCAN_HT16K33	kscan_ht16k33.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library_sources_ifdef(CONFIG_KSCAN_INPUT		kscan_input.c)

zephyr_library_sources_ifdef(CONFIG_USERSPACE	    kscan_handlers.c)
