/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mocks/settings.h"

#include <zephyr/kernel.h>

<<<<<<< HEAD
DEFINE_FAKE_VOID_FUNC(bt_settings_save_id);
=======
DEFINE_FAKE_VOID_FUNC(bt_settings_store_id);
DEFINE_FAKE_VOID_FUNC(bt_settings_delete_id);
DEFINE_FAKE_VOID_FUNC(bt_settings_store_irk);
DEFINE_FAKE_VOID_FUNC(bt_settings_delete_irk);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
