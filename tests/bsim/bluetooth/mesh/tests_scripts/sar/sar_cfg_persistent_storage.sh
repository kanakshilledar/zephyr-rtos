#!/usr/bin/env bash
# Copyright 2023 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# Note:
# Tests must be added in sequence.
# First test sets SAR TX/RX configuration.
# Second test restores it from flash and checks if configuration persisted.
conf=prj_mesh1d1_conf
overlay=overlay_pst_conf
<<<<<<< HEAD
RunTest sar_persistence sar_srv_cfg_store
RunTest sar_persistence sar_srv_cfg_restore
=======
RunTestFlash sar_persistence sar_srv_cfg_store -flash_erase
RunTestFlash sar_persistence sar_srv_cfg_restore -flash_rm

conf=prj_mesh1d1_conf
overlay="overlay_pst_conf_overlay_psa_conf"
RunTestFlash sar_persistence_psa sar_srv_cfg_store -flash_erase
RunTestFlash sar_persistence_psa sar_srv_cfg_restore -flash_rm
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
