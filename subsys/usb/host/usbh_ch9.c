/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

<<<<<<< HEAD
#include <zephyr/kernel.h>
#include <errno.h>
#include <zephyr/drivers/usb/uhc.h>
=======
#include <errno.h>

#include <zephyr/kernel.h>
#include <zephyr/usb/usbh.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <zephyr/usb/usb_ch9.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/net/buf.h>

<<<<<<< HEAD
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(usbh_ch9, CONFIG_USBH_LOG_LEVEL);

#define SETUP_REQ_TIMEOUT	1000U

int usbh_req_setup(const struct device *dev,
		   const uint8_t addr,
=======
#include "usbh_device.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(usbh_ch9, CONFIG_USBH_LOG_LEVEL);

/*
 * For now we set it to the upper limit defined in Chapter
 * "9.2.6.4 Standard Device Requests"
 * This will need to be revised and set depending on the request.
 */
#define SETUP_REQ_TIMEOUT	5000U

K_SEM_DEFINE(ch9_req_sync, 0, 1);

static int ch9_req_cb(struct usb_device *const udev, struct uhc_transfer *const xfer)
{
	LOG_DBG("Request finished %p, err %d", xfer, xfer->err);
	k_sem_give(&ch9_req_sync);

	return 0;
}

int usbh_req_setup(struct usb_device *const udev,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		   const uint8_t bmRequestType,
		   const uint8_t bRequest,
		   const uint16_t wValue,
		   const uint16_t wIndex,
		   const uint16_t wLength,
<<<<<<< HEAD
		   uint8_t *const data)
=======
		   struct net_buf *const buf)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	struct usb_setup_packet req = {
		.bmRequestType = bmRequestType,
		.bRequest = bRequest,
		.wValue = sys_cpu_to_le16(wValue),
		.wIndex = sys_cpu_to_le16(wIndex),
		.wLength = sys_cpu_to_le16(wLength),
	};
	struct uhc_transfer *xfer;
<<<<<<< HEAD
	struct net_buf *buf;
	uint8_t ep = usb_reqtype_is_to_device(&req) ? 0x00 : 0x80;
	int ret;

	xfer = uhc_xfer_alloc(dev, addr, ep, 0, 64, SETUP_REQ_TIMEOUT, NULL);
=======
	uint8_t ep = usb_reqtype_is_to_device(&req) ? 0x00 : 0x80;
	int ret;

	xfer = usbh_xfer_alloc(udev, ep, 0, 64, SETUP_REQ_TIMEOUT, (void *)ch9_req_cb);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	if (!xfer) {
		return -ENOMEM;
	}

<<<<<<< HEAD
	buf = uhc_xfer_buf_alloc(dev, xfer, sizeof(req));
	if (!buf) {
		ret = -ENOMEM;
		goto buf_alloc_err;
	}

	net_buf_add_mem(buf, &req, sizeof(req));

	if (wLength) {
		buf = uhc_xfer_buf_alloc(dev, xfer, wLength);
		if (!buf) {
			ret = -ENOMEM;
			goto buf_alloc_err;
		}

		if (usb_reqtype_is_to_device(&req) && data != NULL) {
			net_buf_add_mem(buf, data, wLength);
		}
	}

	buf = uhc_xfer_buf_alloc(dev, xfer, 0);
	if (!buf) {
		ret = -ENOMEM;
		goto buf_alloc_err;
	}

	return uhc_ep_enqueue(dev, xfer);

buf_alloc_err:
	uhc_xfer_free(dev, xfer);
=======
	memcpy(xfer->setup_pkt, &req, sizeof(req));

	__ASSERT((buf != NULL && wLength) || (buf == NULL && !wLength),
		 "Unresolved conditions for data stage");
	if (wLength) {
		ret = usbh_xfer_buf_add(udev, xfer, buf);
		if (ret) {
			goto buf_alloc_err;
		}
	}

	ret = usbh_xfer_enqueue(udev, xfer);
	if (ret) {
		goto buf_alloc_err;
	}

	k_sem_take(&ch9_req_sync, K_MSEC(SETUP_REQ_TIMEOUT));
	ret = xfer->err;

buf_alloc_err:
	usbh_xfer_free(udev, xfer);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	return ret;
}

<<<<<<< HEAD
int usbh_req_desc(const struct device *dev,
		  const uint8_t addr,
		  const uint8_t type, const uint8_t index,
		  const uint8_t id,
		  const uint16_t len)
=======
int usbh_req_desc(struct usb_device *const udev,
		  const uint8_t type, const uint8_t index,
		  const uint8_t id,
		  const uint16_t len,
		  struct net_buf *const buf)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_HOST << 7;
	const uint8_t bRequest = USB_SREQ_GET_DESCRIPTOR;
	const uint16_t wValue = (type << 8) | index;

<<<<<<< HEAD
	return usbh_req_setup(dev, addr,
			      bmRequestType, bRequest, wValue, id, len,
			      NULL);
}

int usbh_req_desc_dev(const struct device *dev,
		      const uint8_t addr)
{
	const uint8_t type = USB_DESC_DEVICE;
	const uint16_t wLength = 18;

	return usbh_req_desc(dev, addr, type, 0, 0, wLength);
}

int usbh_req_desc_cfg(const struct device *dev,
		      const uint8_t addr,
		      const uint8_t index,
		      const uint16_t len)
{
	const uint8_t type = USB_DESC_CONFIGURATION;

	return usbh_req_desc(dev, addr, type, index, 0, len);
}

int usbh_req_set_address(const struct device *dev,
			 const uint8_t addr, const uint8_t new)
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_DEVICE << 7;
	const uint8_t bRequest = USB_SREQ_SET_ADDRESS;

	return usbh_req_setup(dev, addr,
			      bmRequestType, bRequest, new, 0, 0,
			      NULL);
}

int usbh_req_set_cfg(const struct device *dev,
		     const uint8_t addr, const uint8_t new)
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_DEVICE << 7;
	const uint8_t bRequest = USB_SREQ_SET_CONFIGURATION;

	return usbh_req_setup(dev, addr,
			      bmRequestType, bRequest, new, 0, 0,
			      NULL);
}

int usbh_req_set_alt(const struct device *dev,
		     const uint8_t addr, const uint8_t iface,
		     const uint8_t alt)
=======
	return usbh_req_setup(udev,
			      bmRequestType, bRequest, wValue, id, len,
			      buf);
}

int usbh_req_desc_dev(struct usb_device *const udev,
		      struct usb_device_descriptor *const desc)
{
	const uint8_t type = USB_DESC_DEVICE;
	const uint16_t wLength = sizeof(struct usb_device_descriptor);
	struct net_buf *buf;
	int ret;

	buf = usbh_xfer_buf_alloc(udev, wLength);
	if (!buf) {
		return -ENOMEM;
	}

	ret = usbh_req_desc(udev, type, 0, 0, wLength, buf);
	if (ret == 0 && buf->len == wLength) {
		memcpy(desc, buf->data, wLength);
		desc->bcdUSB = sys_le16_to_cpu(desc->bcdUSB);
		desc->idVendor = sys_le16_to_cpu(desc->idVendor);
		desc->idProduct = sys_le16_to_cpu(desc->idProduct);
		desc->bcdDevice = sys_le16_to_cpu(desc->bcdDevice);
	}

	usbh_xfer_buf_free(udev, buf);

	return ret;
}

int usbh_req_desc_cfg(struct usb_device *const udev,
		      const uint8_t index,
		      const uint16_t len,
		      struct usb_cfg_descriptor *const desc)
{
	const uint8_t type = USB_DESC_CONFIGURATION;
	const uint16_t wLength = len;
	struct net_buf *buf;
	int ret;

	buf = usbh_xfer_buf_alloc(udev, len);
	if (!buf) {
		return -ENOMEM;
	}

	ret = usbh_req_desc(udev, type, index, 0, wLength, buf);
	if (ret == 0) {
		memcpy(desc, buf->data, len);
		desc->wTotalLength = sys_le16_to_cpu(desc->wTotalLength);
	}

	usbh_xfer_buf_free(udev, buf);

	return ret;
}

int usbh_req_set_address(struct usb_device *const udev,
			 const uint8_t addr)
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_DEVICE << 7;
	const uint8_t bRequest = USB_SREQ_SET_ADDRESS;
	int ret;

	ret = usbh_req_setup(udev, bmRequestType, bRequest, addr, 0, 0, NULL);
	if (ret == 0) {
		udev->addr = addr;
		if (addr == 0) {
			udev->state = USB_STATE_DEFAULT;
		}

		if (addr != 0 && udev->state == USB_STATE_DEFAULT) {
			udev->state = USB_STATE_ADDRESSED;
		}
	}

	return ret;
}

int usbh_req_set_cfg(struct usb_device *const udev,
		     const uint8_t cfg)
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_DEVICE << 7;
	const uint8_t bRequest = USB_SREQ_SET_CONFIGURATION;
	int ret;

	/* Ignore the required state change condition for now. */
	ret = usbh_req_setup(udev, bmRequestType, bRequest, cfg, 0, 0, NULL);
	if (ret == 0) {
		udev->actual_cfg = cfg;
		if (cfg == 0) {
			udev->state = USB_STATE_ADDRESSED;
		}

		if (cfg != 0 && udev->state == USB_STATE_ADDRESSED) {
			udev->state = USB_STATE_CONFIGURED;
		}
	}

	return ret;
}

int usbh_req_get_cfg(struct usb_device *const udev,
		     uint8_t *const cfg)
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_HOST << 7;
	const uint8_t bRequest = USB_SREQ_GET_CONFIGURATION;
	const uint16_t wLength = 1;
	struct net_buf *buf;
	int ret;

	buf = usbh_xfer_buf_alloc(udev, wLength);
	if (!buf) {
		return -ENOMEM;
	}

	ret = usbh_req_setup(udev, bmRequestType, bRequest, 0, 0, wLength, buf);
	if (ret == 0 && buf->len == wLength) {
		*cfg = buf->data[0];
	}

	usbh_xfer_buf_free(udev, buf);

	return ret;
}

int usbh_req_set_alt(struct usb_device *const udev,
		     const uint8_t iface, const uint8_t alt)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_DEVICE << 7 |
				      USB_REQTYPE_RECIPIENT_INTERFACE;
	const uint8_t bRequest = USB_SREQ_SET_INTERFACE;
	const uint16_t wValue = alt;
	const uint16_t wIndex = iface;

<<<<<<< HEAD
	return usbh_req_setup(dev, addr,
=======
	return usbh_req_setup(udev,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			      bmRequestType, bRequest, wValue, wIndex, 0,
			      NULL);
}

<<<<<<< HEAD
int usbh_req_set_sfs_rwup(const struct device *dev,
			  const uint8_t addr)
=======
int usbh_req_set_sfs_rwup(struct usb_device *const udev)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_DEVICE << 7;
	const uint8_t bRequest = USB_SREQ_SET_FEATURE;
	const uint16_t wValue = USB_SFS_REMOTE_WAKEUP;

<<<<<<< HEAD
	return usbh_req_setup(dev, addr,
=======
	return usbh_req_setup(udev,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			      bmRequestType, bRequest, wValue, 0, 0,
			      NULL);
}

<<<<<<< HEAD
int usbh_req_clear_sfs_rwup(const struct device *dev,
			    const uint8_t addr)
=======
int usbh_req_clear_sfs_rwup(struct usb_device *const udev)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_DEVICE << 7;
	const uint8_t bRequest = USB_SREQ_CLEAR_FEATURE;
	const uint16_t wValue = USB_SFS_REMOTE_WAKEUP;

<<<<<<< HEAD
	return usbh_req_setup(dev, addr,
=======
	return usbh_req_setup(udev,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			      bmRequestType, bRequest, wValue, 0, 0,
			      NULL);
}

<<<<<<< HEAD
int usbh_req_set_hcfs_ppwr(const struct device *dev,
			   const uint8_t addr, const uint8_t port)
=======
int usbh_req_set_hcfs_ppwr(struct usb_device *const udev,
			   const uint8_t port)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_DEVICE << 7 |
				      USB_REQTYPE_TYPE_CLASS << 5 |
				      USB_REQTYPE_RECIPIENT_OTHER << 0;
	const uint8_t bRequest = USB_HCREQ_SET_FEATURE;
	const uint16_t wValue = USB_HCFS_PORT_POWER;
	const uint16_t wIndex = port;

<<<<<<< HEAD
	return usbh_req_setup(dev, addr,
=======
	return usbh_req_setup(udev,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			      bmRequestType, bRequest, wValue, wIndex, 0,
			      NULL);
}

<<<<<<< HEAD
int usbh_req_set_hcfs_prst(const struct device *dev,
			   const uint8_t addr, const uint8_t port)
=======
int usbh_req_set_hcfs_prst(struct usb_device *const udev,
			   const uint8_t port)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	const uint8_t bmRequestType = USB_REQTYPE_DIR_TO_DEVICE << 7 |
				      USB_REQTYPE_TYPE_CLASS << 5 |
				      USB_REQTYPE_RECIPIENT_OTHER << 0;
	const uint8_t bRequest = USB_HCREQ_SET_FEATURE;
	const uint16_t wValue = USB_HCFS_PORT_RESET;
	const uint16_t wIndex = port;

<<<<<<< HEAD
	return usbh_req_setup(dev, addr,
=======
	return usbh_req_setup(udev,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			      bmRequestType, bRequest, wValue, wIndex, 0,
			      NULL);
}
