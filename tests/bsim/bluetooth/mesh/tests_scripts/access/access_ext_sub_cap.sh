#!/usr/bin/env bash
# Copyright 2022 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

RunTest mesh_access_extended_model_subs_cap access_sub_capacity_ext_model

conf=prj_mesh1d1_conf
RunTest mesh_access_extended_model_subs_cap_1d1 access_sub_capacity_ext_model
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_access_extended_model_subs_cap_psa access_sub_capacity_ext_model
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
