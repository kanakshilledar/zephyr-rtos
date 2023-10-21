#!/usr/bin/env bash
# Copyright 2021 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

overlay=overlay_low_lat_conf
RunTest mesh_transport_loopback_group_low_lat transport_tx_loopback_group transport_rx_group

conf=prj_mesh1d1_conf
overlay=overlay_low_lat_conf
RunTest mesh_transport_loopback_group_low_lat_1d1 transport_tx_loopback_group transport_rx_group
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay="overlay_low_lat_conf_overlay_psa_conf"
RunTest mesh_transport_loopback_group_low_lat_psa transport_tx_loopback_group transport_rx_group
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
