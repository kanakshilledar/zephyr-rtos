/*
 * Copyright (c) 2016 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
<<<<<<< HEAD
=======
 *
 * All references to the spec refer to IEEE 802.15.4-2020.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(net_ieee802154_aloha, CONFIG_NET_L2_IEEE802154_LOG_LEVEL);

<<<<<<< HEAD
#include <zephyr/net/net_core.h>
#include <zephyr/net/net_if.h>

#include <errno.h>

#include "ieee802154_frame.h"
#include "ieee802154_utils.h"
#include "ieee802154_radio_utils.h"

static inline int aloha_radio_send(struct net_if *iface,
				   struct net_pkt *pkt,
				   struct net_buf *frag)
{
	uint8_t retries = CONFIG_NET_L2_IEEE802154_RADIO_TX_RETRIES;
	struct ieee802154_context *ctx = net_if_l2_data(iface);
	bool ack_required = prepare_for_ack(ctx, pkt, frag);
	int ret = -EIO;

	NET_DBG("frag %p", frag);

	while (retries) {
		retries--;

		ret = ieee802154_tx(iface, IEEE802154_TX_MODE_DIRECT,
				    pkt, frag);
		if (ret) {
			continue;
		}

		ret = wait_for_ack(iface, ack_required);
		if (!ret) {
			break;
		}
	}

	return ret;
}

static enum net_verdict aloha_radio_handle_ack(struct net_if *iface,
					       struct net_pkt *pkt)
{
	struct ieee802154_context *ctx = net_if_l2_data(iface);

	if (IS_ENABLED(CONFIG_NET_L2_IEEE802154_RADIO_CSMA_CA) &&
	    ieee802154_get_hw_capabilities(iface) & IEEE802154_HW_CSMA) {
		return NET_OK;
	}

	return handle_ack(ctx, pkt);
}

/* Declare the public Radio driver function used by the HW drivers */
FUNC_ALIAS(aloha_radio_send,
	   ieee802154_radio_send, int);

FUNC_ALIAS(aloha_radio_handle_ack,
	   ieee802154_radio_handle_ack, enum net_verdict);
=======
#include <zephyr/net/net_if.h>

#include "ieee802154_priv.h"

static inline int aloha_channel_access(struct net_if *iface)
{
	ARG_UNUSED(iface);

	/* CCA Mode 4: ALOHA. CCA shall always report an idle medium, see section 10.2.8. */
	return 0;
}

/* Declare the public channel access algorithm function used by L2. */
FUNC_ALIAS(aloha_channel_access, ieee802154_wait_for_clear_channel, int);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
