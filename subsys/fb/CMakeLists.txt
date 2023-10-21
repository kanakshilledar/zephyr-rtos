# SPDX-License-Identifier: Apache-2.0

zephyr_sources_ifdef(CONFIG_CHARACTER_FRAMEBUFFER cfb.c)
zephyr_sources_ifdef(CONFIG_CHARACTER_FRAMEBUFFER_USE_DEFAULT_FONTS cfb_fonts.c)
zephyr_sources_ifdef(CONFIG_CHARACTER_FRAMEBUFFER_SHELL cfb_shell.c)
<<<<<<< HEAD
=======

zephyr_linker_sources_ifdef(CONFIG_CHARACTER_FRAMEBUFFER DATA_SECTIONS check_cfb_fonts.ld)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
