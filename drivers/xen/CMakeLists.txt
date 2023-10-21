# SPDX-License-Identifier: Apache-2.0
<<<<<<< HEAD
# Copyright (c) 2021-2022 EPAM Systems
=======
# Copyright (c) 2021-2023 EPAM Systems
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

zephyr_sources(hvm.c)
zephyr_sources(events.c)
zephyr_sources_ifdef(CONFIG_XEN_GRANT_TABLE gnttab.c)
<<<<<<< HEAD
=======
zephyr_sources(memory.c)

add_subdirectory_ifdef(CONFIG_XEN_DOM0 dom0)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
