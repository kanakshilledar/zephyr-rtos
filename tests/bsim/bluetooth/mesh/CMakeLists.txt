# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(bsim_test_mesh)

target_sources(app PRIVATE
 src/main.c
 src/mesh_test.c
 src/friendship_common.c
)

if(CONFIG_BT_MESH_V1d1)
 target_sources(app PRIVATE
  src/dfu_blob_common.c
 )
endif()

if(CONFIG_SETTINGS)

 target_sources(app PRIVATE
<<<<<<< HEAD
  src/settings_test_backend.c
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
  src/test_persistence.c
  src/test_replay_cache.c
  src/test_provision.c
 )

 if(CONFIG_BT_MESH_V1d1)
  target_sources(app PRIVATE
   src/test_dfu.c
   src/test_blob.c
   src/test_sar.c
<<<<<<< HEAD
 )
 endif()

=======
   src/test_lcd.c
 )
 endif()

if(CONFIG_BT_MESH_USES_MBEDTLS_PSA)
 target_sources(app PRIVATE
  src/distribute_keyid.c
  src/psa_its_emul.c
 )
endif()

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
elseif(CONFIG_BT_MESH_GATT_PROXY)

 target_sources(app PRIVATE
  src/test_advertiser.c
 )

<<<<<<< HEAD
=======
 if(CONFIG_BT_MESH_V1d1)
  target_sources(app PRIVATE
  src/test_beacon.c
  )
  endif()

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
elseif(CONFIG_BT_CTLR_LOW_LAT)

 target_sources(app PRIVATE
  src/test_friendship.c
  src/test_transport.c
 )

else()

 target_sources(app PRIVATE
  src/test_transport.c
  src/test_friendship.c
  src/test_provision.c
  src/test_beacon.c
  src/test_scanner.c
  src/test_heartbeat.c
  src/test_access.c
  src/test_iv_index.c
  src/test_advertiser.c
 )

 if(CONFIG_BT_MESH_V1d1)
  target_sources(app PRIVATE
   src/test_blob.c
   src/test_op_agg.c
   src/test_sar.c
<<<<<<< HEAD
   src/test_lcd.c
=======
   src/test_cdp1.c
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
  )
 endif()

endif()

zephyr_include_directories(
  ${BSIM_COMPONENTS_PATH}/libUtilv1/src/
  ${BSIM_COMPONENTS_PATH}/libPhyComv1/src/
)
<<<<<<< HEAD
=======

# The mbedTLS PSA ITS is not thread safe.
# The issue: https://github.com/zephyrproject-rtos/zephyr/issues/59362
# Also, it isn't possible to use "native" ITS implementation since
# mbedTLS includes headers that do not exist.
# This linker option allows linking custom ITS implementation instead of
# precompiled objects from the mbedTLS library to run it in parallel.
if(CONFIG_BT_MESH_USES_MBEDTLS_PSA)
  zephyr_ld_options(
    ${LINKERFLAGPREFIX},--allow-multiple-definition
    )
endif()
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
