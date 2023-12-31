/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

/*
<<<<<<< HEAD
 *  Validate expected behaviour when settings_delete() is called
 *
 *  Expected behaviour:
 *   - settings_delete() to be called once with correct parameters
 */
void expect_single_call_settings_delete(void);

/*
 *  Validate expected behaviour when settings_save_one() is called
 *
 *  Expected behaviour:
 *   - settings_save_one() to be called once with correct parameters
 */
void expect_single_call_settings_save_one(const void *value);

/*
 *  Validate expected behaviour when settings_save_one() isn't called
 *
 *  Expected behaviour:
 *   - settings_save_one() isn't called at all
 */
void expect_not_called_settings_save_one(void);
=======
 *  Validate expected behaviour when bt_settings_delete_keys() is called
 *
 *  Expected behaviour:
 *   - bt_settings_delete_keys() to be called once with correct parameters
 */
void expect_single_call_bt_settings_delete_keys(void);

/*
 *  Validate expected behaviour when bt_settings_store_keys() is called
 *
 *  Expected behaviour:
 *   - bt_settings_store_keys() to be called once with correct parameters
 */
void expect_single_call_bt_settings_store_keys(const void *value);

/*
 *  Validate expected behaviour when bt_settings_store_keys() isn't called
 *
 *  Expected behaviour:
 *   - bt_settings_store_keys() isn't called at all
 */
void expect_not_called_bt_settings_store_keys(void);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
