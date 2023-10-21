#!/usr/bin/env bash
# Copyright 2023 Nordic Semiconductor ASA
# SPDX-License-Identifier: Apache-2.0

set -eu
bash_source_dir="$(realpath "$(dirname "${BASH_SOURCE[0]}")")"

<<<<<<< HEAD
test_name="$(basename "$(realpath "$bash_source_dir/..")")"
bsim_bin="${BSIM_OUT_PATH}/bin"
verbosity_level=2
BOARD="${BOARD:-nrf52_bsim}"
simulation_id="$test_name"
=======
bsim_bin="${BSIM_OUT_PATH}/bin"
BOARD="${BOARD:-nrf52_bsim}"
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
central_exe="${bsim_bin}/bs_${BOARD}_tests_bsim_bluetooth_host_privacy_central_prj_conf"
peripheral_exe="${central_exe}"
