#!/usr/bin/env bash
#
<<<<<<< HEAD
# Copyright (c) 2022 Nordic Semiconductor ASA
=======
# Copyright (c) 2022-2023 Nordic Semiconductor ASA
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#
# SPDX-License-Identifier: Apache-2.0

dir_path=$(dirname "$0")

<<<<<<< HEAD
$dir_path/cap_unicast.sh

$dir_path/cap_broadcast.sh
=======
set -e # Exit on error

$dir_path/cap_unicast_inval.sh

$dir_path/cap_unicast.sh

$dir_path/cap_broadcast.sh

$dir_path/cap_unicast_ac_1.sh
$dir_path/cap_unicast_ac_2.sh
$dir_path/cap_unicast_ac_3.sh
$dir_path/cap_unicast_ac_4.sh
$dir_path/cap_unicast_ac_5.sh
$dir_path/cap_unicast_ac_6_i.sh
$dir_path/cap_unicast_ac_6_ii.sh
$dir_path/cap_unicast_ac_7_i.sh
$dir_path/cap_unicast_ac_7_ii.sh
$dir_path/cap_unicast_ac_8_i.sh
$dir_path/cap_unicast_ac_8_ii.sh
$dir_path/cap_unicast_ac_9_i.sh
$dir_path/cap_unicast_ac_9_ii.sh
$dir_path/cap_unicast_ac_10.sh
$dir_path/cap_unicast_ac_11_i.sh
$dir_path/cap_unicast_ac_11_ii.sh
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
