# SPDX-License-Identifier: Apache-2.0

zephyr_library()
zephyr_library_sources(bmm150.c bmm150_i2c.c bmm150_spi.c)
<<<<<<< HEAD
=======
zephyr_library_sources_ifdef(CONFIG_BMM150_TRIGGER bmm150_trigger.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
