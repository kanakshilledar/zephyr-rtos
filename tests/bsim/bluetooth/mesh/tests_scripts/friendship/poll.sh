#!/usr/bin/env bash
# Copyright 2021 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# Test poll timeout
RunTest mesh_friendship_poll \
	friendship_friend_est \
	friendship_lpn_poll

conf=prj_mesh1d1_conf
RunTest mesh_friendship_poll_1d1 \
	friendship_friend_est \
	friendship_lpn_poll
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_friendship_poll_psa \
	friendship_friend_est \
	friendship_lpn_poll
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
