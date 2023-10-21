#
# Copyright (c) 2018-2021 mcumgr authors
# Copyright (c) 2022 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: Apache-2.0
#

# The mgmt_mcumgr is interface library for MCUmgr services.
zephyr_interface_library_named(mgmt_mcumgr)

add_subdirectory(mgmt)
add_subdirectory(smp)
add_subdirectory(util)
add_subdirectory(grp)
add_subdirectory(transport)
<<<<<<< HEAD
=======
add_subdirectory_ifdef(CONFIG_SMP_CLIENT    smp_client)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

zephyr_library_link_libraries(mgmt_mcumgr)
