#!/usr/bin/env bash
# Copyright 2022 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# test buffer management by filling buffers and sending them in random order.
RunTest mesh_adv_random_order adv_tx_random_order adv_rx_random_order

conf=prj_mesh1d1_conf
RunTest mesh_adv_random_order_1d1 adv_tx_random_order adv_rx_random_order
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_adv_random_order_psa adv_tx_random_order adv_rx_random_order
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
