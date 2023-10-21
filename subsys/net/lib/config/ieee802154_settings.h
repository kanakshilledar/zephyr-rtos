/* IEEE 802.15.4 settings header */

/*
 * Copyright (c) 2017 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#if defined(CONFIG_NET_L2_IEEE802154) && defined(CONFIG_NET_CONFIG_SETTINGS)
<<<<<<< HEAD
int z_net_config_ieee802154_setup(void);
=======
struct net_if;

int z_net_config_ieee802154_setup(struct net_if *iface);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#else
#define z_net_config_ieee802154_setup(...) 0
#endif
