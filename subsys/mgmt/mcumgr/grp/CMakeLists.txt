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

<<<<<<< HEAD
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_FS        fs_mgmt)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_IMG       img_mgmt)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_OS        os_mgmt)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_STAT      stat_mgmt)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_SHELL     shell_mgmt)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_ZBASIC	   zephyr_basic)
=======
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_FS             fs_mgmt)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_IMG            img_mgmt)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_IMG_CLIENT     img_mgmt_client)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_OS             os_mgmt)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_OS_CLIENT      os_mgmt_client)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_STAT           stat_mgmt)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_SHELL          shell_mgmt)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_ZBASIC         zephyr_basic)
add_subdirectory_ifdef(CONFIG_MCUMGR_GRP_SETTINGS       settings_mgmt)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
