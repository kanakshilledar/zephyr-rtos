# Copyright (c) 2023 Google LLC
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources(akm09918c.c)
<<<<<<< HEAD
zephyr_library_sources_ifdef(CONFIG_EMUL_AKM09918C akm09918c_emul.c)
=======
zephyr_library_sources_ifdef(CONFIG_EMUL_AKM09918C   akm09918c_emul.c)
zephyr_library_sources_ifdef(CONFIG_SENSOR_ASYNC_API akm09918c_async.c akm09918c_decoder.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_include_directories_ifdef(CONFIG_EMUL_AKM09918C .)
