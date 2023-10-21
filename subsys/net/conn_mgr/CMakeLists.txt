# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)

zephyr_library()
zephyr_library_sources(
<<<<<<< HEAD
	conn_mgr.c
=======
	conn_mgr_monitor.c
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	events_handler.c
	conn_mgr_connectivity.c
	)

zephyr_linker_sources(DATA_SECTIONS conn_mgr.ld)
zephyr_iterable_section(NAME conn_mgr_conn_binding GROUP DATA_REGION ${XIP_ALIGN_WITH_INPUT} SUBALIGN 4)
