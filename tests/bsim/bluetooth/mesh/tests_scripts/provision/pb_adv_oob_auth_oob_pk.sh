#!/usr/bin/env bash
# Copyright 2021 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# Test provisioning with OOB authentication and with OOB public key
RunTest mesh_prov_pb_adv_oob_public_key \
	prov_device_pb_adv_oob_public_key prov_provisioner_pb_adv_oob_public_key

conf=prj_mesh1d1_conf
RunTest mesh_prov_pb_adv_oob_public_key_1d1 \
	prov_device_pb_adv_oob_public_key prov_provisioner_pb_adv_oob_public_key
<<<<<<< HEAD
=======

conf=prj_mesh1d1_conf
overlay=overlay_psa_conf
RunTest mesh_prov_pb_adv_oob_public_key_psa \
	prov_device_pb_adv_oob_public_key prov_provisioner_pb_adv_oob_public_key
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
