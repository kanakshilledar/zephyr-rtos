# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_MDIO_SHELL		mdio_shell.c)
zephyr_library_sources_ifdef(CONFIG_MDIO_ATMEL_SAM	mdio_sam.c)
zephyr_library_sources_ifdef(CONFIG_MDIO_ESP32		mdio_esp32.c)
zephyr_library_sources_ifdef(CONFIG_MDIO_NXP_S32_NETC	mdio_nxp_s32_netc.c)
zephyr_library_sources_ifdef(CONFIG_MDIO_ADIN2111	mdio_adin2111.c)
<<<<<<< HEAD
=======
zephyr_library_sources_ifdef(CONFIG_MDIO_GPIO		mdio_gpio.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
