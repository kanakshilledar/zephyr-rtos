#!/usr/bin/env bash
# Copyright 2022 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# test buffer management by filling all the buffer and sending them in reversed order.
RunTest mesh_adv_reverse_order adv_tx_reverse_order adv_rx_receive_order

conf=prj_mesh1d1_conf
RunTest mesh_adv_reverse_order_1d1 adv_tx_reverse_order adv_rx_receive_order
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_adv_reverse_order_psa adv_tx_reverse_order adv_rx_receive_order
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
