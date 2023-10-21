# SPDX-License-Identifier: Apache-2.0
#
# Copyright 2022 NXP

# Add external project
ExternalZephyrProject_Add(
    APPLICATION openamp_remote
    SOURCE_DIR ${APP_DIR}/remote
    BOARD ${SB_CONFIG_OPENAMP_REMOTE_BOARD}
  )

<<<<<<< HEAD
# Add a dependency so that the remote sample will be built and flashed first
# This is required because some primary cores need information from the
# remote core's build, such as the output image's LMA
add_dependencies(openamp openamp_remote)
# Place remote image first in the image list
set(IMAGES "openamp_remote" ${IMAGES})
=======
# Add dependencies so that the remote sample will be built first
# This is required because some primary cores need information from the
# remote core's build, such as the output image's LMA
add_dependencies(openamp openamp_remote)
sysbuild_add_dependencies(CONFIGURE openamp openamp_remote)

if(SB_CONFIG_BOOTLOADER_MCUBOOT)
  # Make sure MCUboot is flashed first
  sysbuild_add_dependencies(FLASH openamp_remote mcuboot)
endif()
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
