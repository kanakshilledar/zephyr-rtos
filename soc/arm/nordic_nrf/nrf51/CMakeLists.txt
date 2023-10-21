# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources(
  soc.c
  )

<<<<<<< HEAD
zephyr_library_sources_ifdef(CONFIG_PM
  power.c
  )

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library_include_directories(
  ${ZEPHYR_BASE}/kernel/include
  ${ZEPHYR_BASE}/arch/arm/include
  )
