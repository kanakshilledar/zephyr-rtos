# Copyright (c) 2022 Intel Corporation
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_RTIO)
<<<<<<< HEAD
=======
	zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/rtio/rtio.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	zephyr_library()

	zephyr_include_directories(${ZEPHYR_BASE}/subsys/rtio)

	zephyr_library_sources(rtio_executor.c)
	zephyr_library_sources(rtio_init.c)
	zephyr_library_sources_ifdef(CONFIG_USERSPACE rtio_handlers.c)
endif()
