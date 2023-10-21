zephyr_sources(
	soc.c
)
zephyr_library_sources_ifndef(CONFIG_RISCV_ISA_EXT_M __arithmetic.S)
zephyr_sources_ifdef(CONFIG_SOC_IT8XXX2_USE_ILM ilm.c)
<<<<<<< HEAD

# IMPORTANT:
# The h2ram section must be first added to RAM_SECTIONS to avoid gap.
zephyr_linker_sources_ifdef(CONFIG_ESPI_IT8XXX2
  RAM_SECTIONS
  h2ram.ld
)
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
