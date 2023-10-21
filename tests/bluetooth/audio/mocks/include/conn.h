/*
 * Copyright (c) 2023 Codecoup
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef MOCKS_CONN_H_
#define MOCKS_CONN_H_

#include <zephyr/bluetooth/conn.h>

struct bt_conn {
	uint8_t index;
	struct bt_conn_info info;
<<<<<<< HEAD
=======
	struct bt_iso_chan *chan;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
};

void mock_bt_conn_disconnected(struct bt_conn *conn, uint8_t err);

#endif /* MOCKS_CONN_H_ */
