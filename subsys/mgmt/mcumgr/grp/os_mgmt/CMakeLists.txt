#
# Copyright (c) 2018-2021 mcumgr authors
<<<<<<< HEAD
# Copyright (c) 2022 Nordic Semiconductor ASA
=======
# Copyright (c) 2022-2023 Nordic Semiconductor ASA
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#
# SPDX-License-Identifier: Apache-2.0
#

# OS Management group public API is exposed through zephyr_interface,
# when OS Management is enabled.
zephyr_library(mgmt_mcumgr_grp_os)
zephyr_library_sources(src/os_mgmt.c)

zephyr_library_include_directories(include)

<<<<<<< HEAD
=======
if (CONFIG_MCUMGR_GRP_OS_BOOTLOADER_INFO)
    zephyr_include_directories(
        ${ZEPHYR_MCUBOOT_MODULE_DIR}/boot/bootutil/include
    )
endif()

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
if(DEFINED CONFIG_MCUMGR_GRP_OS_INFO_BUILD_DATE_TIME)
  set(MCUMGR_GRP_OS_INFO_BUILD_DATE_TIME_DIR ${PROJECT_BINARY_DIR}/os_mgmt_auto)
  file(MAKE_DIRECTORY ${MCUMGR_GRP_OS_INFO_BUILD_DATE_TIME_DIR})
  file(WRITE ${MCUMGR_GRP_OS_INFO_BUILD_DATE_TIME_DIR}/os_mgmt_build_date.c "/* Auto generated file, do not edit */\n#include <stdint.h>\nuint8_t *MCUMGR_GRP_OS_INFO_BUILD_DATE_TIME = __TIMESTAMP__;")
  zephyr_library_sources(${MCUMGR_GRP_OS_INFO_BUILD_DATE_TIME_DIR}/os_mgmt_build_date.c)
endif()
