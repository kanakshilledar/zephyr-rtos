/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include "mocks/conn.h"

<<<<<<< HEAD
DEFINE_FAKE_VOID_FUNC(bt_conn_foreach, int, bt_conn_foreach_cb, void *);
=======
DEFINE_FAKE_VOID_FUNC(bt_conn_foreach, enum bt_conn_type, bt_conn_foreach_cb, void *);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
DEFINE_FAKE_VALUE_FUNC(const bt_addr_le_t *, bt_conn_get_dst, const struct bt_conn *);
