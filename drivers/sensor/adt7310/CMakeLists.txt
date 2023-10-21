# SPDX-License-Identifier: Apache-2.0

zephyr_library()

<<<<<<< HEAD
zephyr_library_sources_ifdef(CONFIG_ADT7310 adt7310.c)
=======
zephyr_library_sources(adt7310.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library_sources_ifdef(CONFIG_ADT7310_TRIGGER adt7310_trigger.c)
