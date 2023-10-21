#!/usr/bin/env bash
# Copyright 2021 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

RunTest mesh_beacon_on_key_refresh \
	beacon_tx_on_key_refresh \
	beacon_rx_on_key_refresh

conf=prj_mesh1d1_conf
RunTest mesh_beacon_on_key_refresh_1d1 \
	beacon_tx_on_key_refresh \
	beacon_rx_on_key_refresh
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_beacon_on_key_refresh_psa \
	beacon_tx_on_key_refresh \
	beacon_rx_on_key_refresh
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
