#!/usr/bin/env bash
# Copyright 2022 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# Test that BLOB Client can resume a suspended BLOB Transfer in Push mode
conf=prj_mesh1d1_conf
RunTest blob_resume_push blob_cli_trans_resume blob_srv_trans_resume
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest blob_resume_push_psa blob_cli_trans_resume blob_srv_trans_resume
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
