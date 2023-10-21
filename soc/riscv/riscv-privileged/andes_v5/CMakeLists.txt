# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(${CONFIG_SOC})

zephyr_sources(
  start.S
  soc_irq.S
<<<<<<< HEAD
  l2_cache.c
)

zephyr_sources_ifdef(CONFIG_SOC_ANDES_V5_PMA pma.c)
=======
)

zephyr_sources_ifdef(CONFIG_SOC_ANDES_V5_PMA pma.c)
zephyr_sources_ifdef(CONFIG_SOC_ANDES_V5_L2C l2_cache.c)
zephyr_linker_sources(ROM_START SORT_KEY 0x0 common_linker/init.ld)
zephyr_linker_sources_ifdef(CONFIG_SOC_ANDES_V5_EXECIT RODATA SORT_KEY 0x0 common_linker/execit.ld)
zephyr_linker_sources_ifdef(CONFIG_XIP RAM_SECTIONS SORT_KEY 0x0 common_linker/ram_start_nonzero.ld)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

# Note: AndeStar V5 DSP needs custom Andes V5 toolchain
if(CONFIG_SOC_ANDES_V5_HWDSP)
  zephyr_cc_option(-mext-dsp)
endif()
<<<<<<< HEAD
=======

# Note: AndeStar V5 EXEC.IT needs custom Andes V5 toolchain
if(CONFIG_SOC_ANDES_V5_EXECIT)
  zephyr_cc_option(-mexecit)
  zephyr_ld_options(-Wl,--mexecit)
endif()
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
