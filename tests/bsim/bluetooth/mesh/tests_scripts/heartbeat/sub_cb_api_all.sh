#!/usr/bin/env bash
# Copyright 2021 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# Run all nodes heartbeat subscription to a device
RunTest mesh_heartbeat_sub_cb_api_all \
	heartbeat_publish_all \
	heartbeat_publish_all \
	heartbeat_subscribe_all

conf=prj_mesh1d1_conf
RunTest mesh_heartbeat_sub_cb_api_all_1d1 \
	heartbeat_publish_all \
	heartbeat_publish_all \
	heartbeat_subscribe_all
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_heartbeat_sub_cb_api_all_psa \
	heartbeat_publish_all \
	heartbeat_publish_all \
	heartbeat_subscribe_all
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
