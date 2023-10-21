/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_USBH_CH9_H
#define ZEPHYR_INCLUDE_USBH_CH9_H

#include <stdint.h>
#include <zephyr/usb/usbh.h>

<<<<<<< HEAD
int usbh_req_setup(const struct device *dev,
		   const uint8_t addr,
=======
#include "usbh_device.h"

int usbh_req_setup(struct usb_device *const udev,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		   const uint8_t bmRequestType,
		   const uint8_t bRequest,
		   const uint16_t wValue,
		   const uint16_t wIndex,
		   const uint16_t wLength,
<<<<<<< HEAD
		   uint8_t *const data);

int usbh_req_desc(const struct device *dev,
		  const uint8_t addr,
		  const uint8_t type, const uint8_t index,
		  const uint8_t id,
		  const uint16_t len);

int usbh_req_desc_dev(const struct device *dev,
		      const uint8_t addr);

int usbh_req_desc_cfg(const struct device *dev,
		      const uint8_t addr,
		      const uint8_t index,
		      const uint16_t len);

int usbh_req_set_alt(const struct device *dev,
		     const uint8_t addr, const uint8_t iface,
		     const uint8_t alt);

int usbh_req_set_address(const struct device *dev,
			 const uint8_t addr, const uint8_t new);

int usbh_req_set_cfg(const struct device *dev,
		     const uint8_t addr, const uint8_t new);

int usbh_req_set_sfs_rwup(const struct device *dev,
			  const uint8_t addr);

int usbh_req_clear_sfs_rwup(const struct device *dev,
			    const uint8_t addr);

int usbh_req_set_hcfs_ppwr(const struct device *dev,
			   const uint8_t addr, const uint8_t port);

int usbh_req_set_hcfs_prst(const struct device *dev,
			   const uint8_t addr, const uint8_t port);
=======
		   struct net_buf *const data);

int usbh_req_desc(struct usb_device *const udev,
		  const uint8_t type, const uint8_t index,
		  const uint8_t id,
		  const uint16_t len,
		  struct net_buf *const data);

int usbh_req_desc_dev(struct usb_device *const udev,
		      struct usb_device_descriptor *const dev);

int usbh_req_desc_cfg(struct usb_device *const udev,
		      const uint8_t index,
		      const uint16_t len,
		      struct usb_cfg_descriptor *const desc);

int usbh_req_set_alt(struct usb_device *const udev,
		     const uint8_t iface,
		     const uint8_t alt);

int usbh_req_set_address(struct usb_device *const udev,
			 const uint8_t addr);

int usbh_req_set_cfg(struct usb_device *const udev,
		     const uint8_t cfg);

int usbh_req_get_cfg(struct usb_device *const udev,
		     uint8_t *const cfg);

int usbh_req_set_sfs_rwup(struct usb_device *const udev);

int usbh_req_clear_sfs_rwup(struct usb_device *const udev);

int usbh_req_set_hcfs_ppwr(const struct usb_device *udev,
			   const uint8_t port);

int usbh_req_set_hcfs_prst(const struct usb_device *udev,
			   const uint8_t port);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#endif /* ZEPHYR_INCLUDE_USBH_CH9_H */
