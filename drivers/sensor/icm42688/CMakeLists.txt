# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources(
    icm42688.c
    icm42688_common.c
    icm42688_spi.c
)

<<<<<<< HEAD
=======
zephyr_library_sources_ifdef(CONFIG_SENSOR_ASYNC_API icm42688_rtio.c)
zephyr_library_sources_ifdef(CONFIG_ICM42688_DECODER icm42688_decoder.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library_sources_ifdef(CONFIG_ICM42688_TRIGGER icm42688_trigger.c)
zephyr_library_sources_ifdef(CONFIG_EMUL_ICM42688 icm42688_emul.c)
zephyr_include_directories_ifdef(CONFIG_EMUL_ICM42688 .)
