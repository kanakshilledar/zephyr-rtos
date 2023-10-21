/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "bs_bt_utils.h"
<<<<<<< HEAD
#include "zephyr/bluetooth/addr.h"
#include "zephyr/bluetooth/conn.h"
=======
#include <zephyr/bluetooth/addr.h>
#include <zephyr/bluetooth/conn.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#include <stdint.h>

#include <zephyr/bluetooth/bluetooth.h>

void central(void)
{
	bs_bt_utils_setup();

	printk("== Bonding id a ==\n");
	scan_connect_to_first_result();
	wait_connected();
	set_security(BT_SECURITY_L2);
	TAKE_FLAG(flag_pairing_complete);
	disconnect();
	wait_disconnected();
	clear_g_conn();

	printk("== Bonding id b ==\n");
	scan_connect_to_first_result();
	wait_connected();
	set_security(BT_SECURITY_L2);
	wait_disconnected();
	PASS("PASS\n");
}
