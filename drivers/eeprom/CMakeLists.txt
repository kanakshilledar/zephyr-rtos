# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/eeprom.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library()

zephyr_library_sources_ifdef(CONFIG_USERSPACE eeprom_handlers.c)
zephyr_library_sources_ifdef(CONFIG_EEPROM_SHELL eeprom_shell.c)

zephyr_library_sources_ifdef(CONFIG_EEPROM_AT2X eeprom_at2x.c)
zephyr_library_sources_ifdef(CONFIG_EEPROM_LPC11U6X eeprom_lpc11u6x.c)
zephyr_library_sources_ifdef(CONFIG_EEPROM_STM32 eeprom_stm32.c)
zephyr_library_sources_ifdef(CONFIG_EEPROM_SIMULATOR eeprom_simulator.c)
zephyr_library_sources_ifdef(CONFIG_EEPROM_EMULATOR eeprom_emulator.c)
zephyr_library_sources_ifdef(CONFIG_EEPROM_TMP116 eeprom_tmp116.c)
zephyr_library_sources_ifdef(CONFIG_EEPROM_XEC eeprom_mchp_xec.c)
zephyr_library_sources_ifdef(CONFIG_EEPROM_FAKE eeprom_fake.c)

zephyr_library_sources_ifdef(CONFIG_EEPROM_AT2X_EMUL eeprom_at2x_emul.c)
<<<<<<< HEAD
=======

zephyr_library_sources_ifdef(CONFIG_EEPROM_MB85RCXX eeprom_mb85rcxx.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
