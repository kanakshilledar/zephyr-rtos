# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_compile_definitions(NO_POSIX_CHEATS)

zephyr_library_sources(
	soc.c
<<<<<<< HEAD
=======
	native_tasks.c
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	)

zephyr_library_include_directories(
  ${ZEPHYR_BASE}/kernel/include
  ${ZEPHYR_BASE}/arch/posix/include
  )
