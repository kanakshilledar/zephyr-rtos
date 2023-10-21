# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(${ZEPHYR_BASE}/drivers)
zephyr_sources(
  soc.c
  )
<<<<<<< HEAD
=======
zephyr_linker_sources(SECTIONS sections.ld)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
