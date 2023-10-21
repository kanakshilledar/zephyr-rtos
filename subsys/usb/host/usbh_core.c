/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <zephyr/device.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/devicetree.h>
<<<<<<< HEAD
#include "usbh_internal.h"
#include <zephyr/sys/iterable_sections.h>
=======
#include <zephyr/init.h>
#include <zephyr/sys/iterable_sections.h>

#include "usbh_internal.h"
#include "usbh_device.h"

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(uhs, CONFIG_USBH_LOG_LEVEL);

static K_KERNEL_STACK_DEFINE(usbh_stack, CONFIG_USBH_STACK_SIZE);
static struct k_thread usbh_thread_data;

<<<<<<< HEAD
/* TODO */
static struct usbh_class_data *class_data;

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
K_MSGQ_DEFINE(usbh_msgq, sizeof(struct uhc_event),
	      CONFIG_USBH_MAX_UHC_MSG, sizeof(uint32_t));

static int usbh_event_carrier(const struct device *dev,
			      const struct uhc_event *const event)
{
	return k_msgq_put(&usbh_msgq, event, K_NO_WAIT);
}

<<<<<<< HEAD
static int event_ep_request(struct usbh_contex *const ctx,
			    struct uhc_event *const event)
{
	struct uhc_transfer *xfer = event->xfer;
	const struct device *dev = ctx->dev;

	if (class_data && class_data->request) {
		return class_data->request(ctx, event->xfer, event->status);
	}

	while (!k_fifo_is_empty(&xfer->done)) {
		struct net_buf *buf;

		buf = net_buf_get(&xfer->done, K_NO_WAIT);
		if (buf) {
			LOG_HEXDUMP_INF(buf->data, buf->len, "buf");
			uhc_xfer_buf_free(dev, buf);
		}
=======
static int discard_ep_request(struct usbh_contex *const ctx,
			      struct uhc_transfer *const xfer)
{
	const struct device *dev = ctx->dev;

	if (xfer->buf) {
		LOG_HEXDUMP_INF(xfer->buf->data, xfer->buf->len, "buf");
		uhc_xfer_buf_free(dev, xfer->buf);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	return uhc_xfer_free(dev, xfer);
}

<<<<<<< HEAD
static int ALWAYS_INLINE usbh_event_handler(struct usbh_contex *const ctx,
=======
static ALWAYS_INLINE int usbh_event_handler(struct usbh_contex *const ctx,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
					    struct uhc_event *const event)
{
	int ret = 0;

<<<<<<< HEAD
=======
	if (event->type == UHC_EVT_EP_REQUEST) {
		struct usb_device *const udev = event->xfer->udev;
		usbh_udev_cb_t cb = event->xfer->cb;

		if (event->xfer->cb) {
			ret = cb(udev, event->xfer);
		} else {
			ret = discard_ep_request(ctx, event->xfer);
		}
		return ret;
	}

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	switch (event->type) {
	case UHC_EVT_DEV_CONNECTED_LS:
	case UHC_EVT_DEV_CONNECTED_FS:
	case UHC_EVT_DEV_CONNECTED_HS:
		LOG_DBG("Device connected event");
<<<<<<< HEAD
		if (class_data && class_data->connected) {
			ret = class_data->connected(ctx);
		}
		break;
	case UHC_EVT_DEV_REMOVED:
		LOG_DBG("Device removed event");
		if (class_data && class_data->removed) {
			ret = class_data->removed(ctx);
		}
		break;
	case UHC_EVT_RESETED:
		LOG_DBG("Bus reseted");
		/* TODO */
		if (class_data && class_data->removed) {
			ret = class_data->removed(ctx);
		}
		break;
	case UHC_EVT_SUSPENDED:
		LOG_DBG("Bus suspended");
		if (class_data && class_data->suspended) {
			ret = class_data->suspended(ctx);
		}
		break;
	case UHC_EVT_RESUMED:
		LOG_DBG("Bus resumed");
		if (class_data && class_data->resumed) {
			ret = class_data->resumed(ctx);
		}
		break;
	case UHC_EVT_RWUP:
		LOG_DBG("RWUP event");
		if (class_data && class_data->rwup) {
			ret = class_data->rwup(ctx);
		}
		break;
	case UHC_EVT_EP_REQUEST:
		event_ep_request(ctx, event);
		break;
	case UHC_EVT_ERROR:
		LOG_DBG("Error event");
=======
		break;
	case UHC_EVT_DEV_REMOVED:
		LOG_DBG("Device removed event");
		break;
	case UHC_EVT_RESETED:
		LOG_DBG("Bus reset");
		break;
	case UHC_EVT_SUSPENDED:
		LOG_DBG("Bus suspended");
		break;
	case UHC_EVT_RESUMED:
		LOG_DBG("Bus resumed");
		break;
	case UHC_EVT_RWUP:
		LOG_DBG("RWUP event");
		break;
	case UHC_EVT_ERROR:
		LOG_DBG("Error event %d", event->status);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		break;
	default:
		break;
	};

	return ret;
}

static void usbh_thread(const struct device *dev)
{
	struct uhc_event event;

	while (true) {
		k_msgq_get(&usbh_msgq, &event, K_FOREVER);

		STRUCT_SECTION_FOREACH(usbh_contex, uhs_ctx) {
			if (uhs_ctx->dev == event.dev) {
				usbh_event_handler(uhs_ctx, &event);
			}
		}
	}
}

int usbh_init_device_intl(struct usbh_contex *const uhs_ctx)
{
	int ret;

	ret = uhc_init(uhs_ctx->dev, usbh_event_carrier);
	if (ret != 0) {
		LOG_ERR("Failed to init device driver");
		return ret;
	}

	STRUCT_SECTION_FOREACH(usbh_class_data, cdata) {
<<<<<<< HEAD
		LOG_DBG("class data %p", cdata);
		/* TODO */
		class_data = cdata;
=======
		/*
		 * For now, we have not implemented any class drivers,
		 * so just keep it as placeholder.
		 */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		break;
	}

	return 0;
}

static int uhs_pre_init(void)
{
	k_thread_create(&usbh_thread_data, usbh_stack,
			K_KERNEL_STACK_SIZEOF(usbh_stack),
			(k_thread_entry_t)usbh_thread,
			NULL, NULL, NULL,
			K_PRIO_COOP(9), 0, K_NO_WAIT);

	k_thread_name_set(&usbh_thread_data, "usbh");

	return 0;
}

SYS_INIT(uhs_pre_init, POST_KERNEL, CONFIG_USBH_INIT_PRIO);
