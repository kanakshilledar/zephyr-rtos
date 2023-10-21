/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mocks/settings.h"
#include "mocks/settings_expects.h"

#include <zephyr/kernel.h>

<<<<<<< HEAD
void expect_single_call_bt_settings_save_id(void)
{
	const char *func_name = "bt_settings_save_id";

	zassert_equal(bt_settings_save_id_fake.call_count, 1, "'%s()' was called more than once",
		      func_name);
}

void expect_not_called_bt_settings_save_id(void)
{
	const char *func_name = "bt_settings_save_id";

	zassert_equal(bt_settings_save_id_fake.call_count, 0, "'%s()' was called unexpectedly",
=======
void expect_single_call_bt_settings_store_id(void)
{
	const char *func_name = "bt_settings_store_id";

	zassert_equal(bt_settings_store_id_fake.call_count, 1, "'%s()' was called more than once",
		      func_name);
}

void expect_not_called_bt_settings_store_id(void)
{
	const char *func_name = "bt_settings_store_id";

	zassert_equal(bt_settings_store_id_fake.call_count, 0, "'%s()' was called unexpectedly",
		      func_name);
}

void expect_single_call_bt_settings_store_irk(void)
{
	const char *func_name = "bt_settings_store_irk";

	zassert_equal(bt_settings_store_irk_fake.call_count, 1, "'%s()' was called more than once",
		      func_name);
}

void expect_not_called_bt_settings_store_irk(void)
{
	const char *func_name = "bt_settings_store_irk";

	zassert_equal(bt_settings_store_irk_fake.call_count, 0, "'%s()' was called unexpectedly",
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		      func_name);
}
