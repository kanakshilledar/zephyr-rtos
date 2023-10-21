/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/bluetooth/buf.h>
#include <host/keys.h>
#include "mocks/settings_store.h"
#include "mocks/settings_store_expects.h"

<<<<<<< HEAD
void expect_single_call_settings_delete(void)
{
	const char *func_name = "settings_delete";

	zassert_equal(settings_delete_fake.call_count, 1, "'%s()' was called more than once",
		      func_name);

	zassert_not_null(settings_delete_fake.arg0_val,
			 "'%s()' was called with incorrect '%s' value", func_name, "key");
}

void expect_single_call_settings_save_one(const void *value)
{
	const char *func_name = "settings_save_one";

	zassert_equal(settings_save_one_fake.call_count, 1, "'%s()' was called more than once",
		      func_name);

	zassert_not_null(settings_save_one_fake.arg0_val,
			 "'%s()' was called with incorrect '%s' value", func_name, "key");
	zassert_equal(settings_save_one_fake.arg1_val, value,
		      "'%s()' was called with incorrect '%s' value", func_name, "value");
	zassert_equal(settings_save_one_fake.arg2_val, BT_KEYS_STORAGE_LEN,
		      "'%s()' was called with incorrect '%s' value", func_name, "val_len");
}

void expect_not_called_settings_save_one(void)
{
	const char *func_name = "settings_save_one";

	zassert_equal(settings_save_one_fake.call_count, 0, "'%s()' was called unexpectedly",
=======
void expect_single_call_bt_settings_delete_keys(void)
{
	const char *func_name = "bt_settings_delete_keys";

	zassert_equal(bt_settings_delete_keys_fake.call_count, 1,
		      "'%s()' was called more than once", func_name);
}

void expect_single_call_bt_settings_store_keys(const void *value)
{
	const char *func_name = "bt_settings_store_keys";

	zassert_equal(bt_settings_store_keys_fake.call_count, 1, "'%s()' was called more than once",
		      func_name);

	zassert_equal(bt_settings_store_keys_fake.arg2_val, value,
		      "'%s()' was called with incorrect '%s' value", func_name, "value");
	zassert_equal(bt_settings_store_keys_fake.arg3_val, BT_KEYS_STORAGE_LEN,
		      "'%s()' was called with incorrect '%s' value", func_name, "val_len");
}

void expect_not_called_bt_settings_store_keys(void)
{
	const char *func_name = "bt_settings_store_keys";

	zassert_equal(bt_settings_store_keys_fake.call_count, 0, "'%s()' was called unexpectedly",
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		      func_name);
}
