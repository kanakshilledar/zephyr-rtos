#!/usr/bin/env bash
# Copyright 2022 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# test deferring of the IV index update procedure
RunTest mesh_ivi_deferring ivi_ivu_deferring

conf=prj_mesh1d1_conf
RunTest mesh_ivi_deferring_1d1 ivi_ivu_deferring
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_ivi_deferring_psa ivi_ivu_deferring
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
