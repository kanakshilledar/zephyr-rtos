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
LOG_MODULE_REGISTER(net_ieee802154_csma, CONFIG_NET_L2_IEEE802154_LOG_LEVEL);

<<<<<<< HEAD
#include <zephyr/net/net_core.h>
#include <zephyr/net/net_if.h>

#include <zephyr/sys/util.h>
#include <zephyr/random/rand32.h>

#include <stdlib.h>
#include <errno.h>

#include "ieee802154_frame.h"
#include "ieee802154_utils.h"
#include "ieee802154_radio_utils.h"

static inline int csma_ca_radio_send(struct net_if *iface,
				     struct net_pkt *pkt,
				     struct net_buf *frag)
{
	const uint8_t max_bo = CONFIG_NET_L2_IEEE802154_RADIO_CSMA_CA_MAX_BO;
	const uint8_t max_be = CONFIG_NET_L2_IEEE802154_RADIO_CSMA_CA_MAX_BE;
	uint8_t retries = CONFIG_NET_L2_IEEE802154_RADIO_TX_RETRIES;
	struct ieee802154_context *ctx = net_if_l2_data(iface);
	bool ack_required = prepare_for_ack(ctx, pkt, frag);
	uint8_t be = CONFIG_NET_L2_IEEE802154_RADIO_CSMA_CA_MIN_BE;
	uint8_t nb = 0U;
	int ret = -EIO;

	NET_DBG("frag %p", frag);

loop:
	while (retries) {
		retries--;
=======
#include <zephyr/net/ieee802154.h>
#include <zephyr/net/ieee802154_radio.h>
#include <zephyr/net/net_if.h>
#include <zephyr/random/random.h>
#include <zephyr/toolchain.h>

#include <errno.h>
#include <stdlib.h>

#include "ieee802154_priv.h"
#include "ieee802154_utils.h"

BUILD_ASSERT(CONFIG_NET_L2_IEEE802154_RADIO_CSMA_CA_MIN_BE <=
		     CONFIG_NET_L2_IEEE802154_RADIO_CSMA_CA_MAX_BE,
	     "The CSMA/CA min backoff exponent must be less or equal max backoff exponent.");

/* See section 6.2.5.1. */
static inline int unslotted_csma_ca_channel_access(struct net_if *iface)
{
	struct ieee802154_context *ctx = net_if_l2_data(iface);
	uint8_t be = CONFIG_NET_L2_IEEE802154_RADIO_CSMA_CA_MIN_BE;
	uint32_t turnaround_time, unit_backoff_period_us;

	turnaround_time = ieee802154_radio_get_a_turnaround_time(iface);
	unit_backoff_period_us = ieee802154_radio_get_multiple_of_symbol_period(
					 iface, ctx->channel,
					 IEEE802154_MAC_A_UNIT_BACKOFF_PERIOD(turnaround_time)) /
				 NSEC_PER_USEC;

	for (uint8_t nb = 0U; nb <= CONFIG_NET_L2_IEEE802154_RADIO_CSMA_CA_MAX_BO; nb++) {
		int ret;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

		if (be) {
			uint8_t bo_n = sys_rand32_get() & ((1 << be) - 1);

<<<<<<< HEAD
			k_busy_wait(bo_n * 20U);
		}

		while (1) {
			if (!ieee802154_cca(iface)) {
				break;
			}

			be = MIN(be + 1, max_be);
			nb++;

			if (nb > max_bo) {
				goto loop;
			}
		}

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

static enum net_verdict csma_ca_radio_handle_ack(struct net_if *iface,
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
FUNC_ALIAS(csma_ca_radio_send,
	   ieee802154_radio_send, int);

FUNC_ALIAS(csma_ca_radio_handle_ack,
	   ieee802154_radio_handle_ack, enum net_verdict);
=======
			/* TODO: k_busy_wait() is too inaccurate on many platforms, the
			 * radio API should expose a precise radio clock instead (which may
			 * fall back to k_busy_wait() if the radio does not have a clock).
			 */
			k_busy_wait(bo_n * unit_backoff_period_us);
		}

		ret = ieee802154_radio_cca(iface);
		if (ret == 0) {
			/* Channel is idle -> CSMA Success */
			return 0;
		} else if (ret != -EBUSY) {
			/* CCA exited with failure code -> CSMA Abort */
			return -EIO;
		}

		/* Channel is busy -> CSMA Backoff */
		be = MIN(be + 1, CONFIG_NET_L2_IEEE802154_RADIO_CSMA_CA_MAX_BE);
	}

	/* Channel is still busy after max backoffs -> CSMA Failure */
	return -EBUSY;
}

/* Declare the public channel access algorithm function used by L2. */
FUNC_ALIAS(unslotted_csma_ca_channel_access, ieee802154_wait_for_clear_channel, int);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
