#!/usr/bin/env bash
# Copyright 2022 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

RunTest mesh_beacon_kr_old_key \
	beacon_tx_kr_old_key \
	beacon_rx_kr_old_key

conf=prj_mesh1d1_conf
RunTest mesh_beacon_kr_old_key_1d1 \
	beacon_tx_kr_old_key \
	beacon_rx_kr_old_key
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_beacon_kr_old_key_psa \
	beacon_tx_kr_old_key \
	beacon_rx_kr_old_key
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
