# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/reset.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library()
zephyr_library_sources_ifdef(CONFIG_RESET_GD32 reset_gd32.c)
zephyr_library_sources_ifdef(CONFIG_RESET_RPI_PICO reset_rpi_pico.c)
zephyr_library_sources_ifdef(CONFIG_RESET_AST10X0 reset_ast10x0.c)
zephyr_library_sources_ifdef(CONFIG_RESET_STM32 reset_stm32.c)
<<<<<<< HEAD
=======
zephyr_library_sources_ifdef(CONFIG_RESET_NUMAKER reset_numaker.c)
zephyr_library_sources_ifdef(CONFIG_RESET_INTEL_SOCFPGA reset_intel_socfpga.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
