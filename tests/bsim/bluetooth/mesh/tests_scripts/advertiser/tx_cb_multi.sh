#!/usr/bin/env bash
# Copyright 2022 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# test tx callbacks sequence for multiple advs
RunTest mesh_adv_tx_cb_multi adv_tx_cb_multi

conf=prj_mesh1d1_conf
RunTest mesh_adv_tx_cb_multi_1d1 adv_tx_cb_multi
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_adv_tx_cb_multi_psa adv_tx_cb_multi
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
