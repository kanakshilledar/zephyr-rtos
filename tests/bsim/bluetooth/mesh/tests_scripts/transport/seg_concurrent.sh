#!/usr/bin/env bash
# Copyright 2021 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

RunTest mesh_transport_seg_concurrent transport_tx_seg_concurrent transport_rx_seg_concurrent

conf=prj_mesh1d1_conf
RunTest mesh_transport_seg_concurrent_1d1 transport_tx_seg_concurrent transport_rx_seg_concurrent
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_transport_seg_concurrent_psa transport_tx_seg_concurrent transport_rx_seg_concurrent
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
