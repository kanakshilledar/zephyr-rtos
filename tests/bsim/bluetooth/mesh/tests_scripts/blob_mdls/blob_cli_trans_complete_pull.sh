#!/usr/bin/env bash
# Copyright 2022 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# Test that BLOB Transfer completes successfully in Pull mode
conf=prj_mesh1d1_conf
RunTest blob_success_pull blob_cli_trans_complete \
	blob_srv_trans_complete blob_srv_trans_complete \
	blob_srv_trans_complete blob_srv_trans_complete \
	-- -argstest use-pull-mode=1
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest blob_success_pull_psa blob_cli_trans_complete \
	blob_srv_trans_complete blob_srv_trans_complete \
	blob_srv_trans_complete blob_srv_trans_complete \
	-- -argstest use-pull-mode=1
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
