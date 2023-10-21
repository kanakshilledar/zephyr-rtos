/*
 * Copyright (c) 2018 PHYTEC Messtechnik GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

<<<<<<< HEAD
#define DT_DRV_COMPAT solomon_ssd1306fb

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(ssd1306, CONFIG_DISPLAY_LOG_LEVEL);

#include <string.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/kernel.h>

#include "ssd1306_regs.h"

<<<<<<< HEAD
#if DT_INST_PROP(0, segment_remap) == 1
#define SSD1306_PANEL_SEGMENT_REMAP	true
#else
#define SSD1306_PANEL_SEGMENT_REMAP	false
#endif

#if DT_INST_PROP(0, com_invdir) == 1
#define SSD1306_PANEL_COM_INVDIR	true
#else
#define SSD1306_PANEL_COM_INVDIR	false
#endif

#if DT_INST_PROP(0, com_sequential) == 1
#define SSD1306_COM_PINS_HW_CONFIG	SSD1306_SET_PADS_HW_SEQUENTIAL
#else
#define SSD1306_COM_PINS_HW_CONFIG	SSD1306_SET_PADS_HW_ALTERNATIVE
#endif

#define SSD1306_PANEL_NUMOF_PAGES	(DT_INST_PROP(0, height) / 8)
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#define SSD1306_CLOCK_DIV_RATIO		0x0
#define SSD1306_CLOCK_FREQUENCY		0x8
#define SSD1306_PANEL_VCOM_DESEL_LEVEL	0x20
#define SSD1306_PANEL_PUMP_VOLTAGE	SSD1306_SET_PUMP_VOLTAGE_90

#ifndef SSD1306_ADDRESSING_MODE
#define SSD1306_ADDRESSING_MODE		(SSD1306_SET_MEM_ADDRESSING_HORIZONTAL)
#endif

<<<<<<< HEAD
struct ssd1306_config {
#if DT_INST_ON_BUS(0, i2c)
	struct i2c_dt_spec bus;
#elif DT_INST_ON_BUS(0, spi)
	struct spi_dt_spec bus;
	struct gpio_dt_spec data_cmd;
#endif
	struct gpio_dt_spec reset;
=======
union ssd1306_bus {
	struct i2c_dt_spec i2c;
	struct spi_dt_spec spi;
};

typedef bool (*ssd1306_bus_ready_fn)(const struct device *dev);
typedef int (*ssd1306_write_bus_fn)(const struct device *dev, uint8_t *buf, size_t len,
				    bool command);
typedef const char *(*ssd1306_bus_name_fn)(const struct device *dev);

struct ssd1306_config {
	union ssd1306_bus bus;
	struct gpio_dt_spec data_cmd;
	struct gpio_dt_spec reset;
	ssd1306_bus_ready_fn bus_ready;
	ssd1306_write_bus_fn write_bus;
	ssd1306_bus_name_fn bus_name;
	uint16_t height;
	uint16_t width;
	uint8_t segment_offset;
	uint8_t page_offset;
	uint8_t display_offset;
	uint8_t multiplex_ratio;
	uint8_t prechargep;
	bool segment_remap;
	bool com_invdir;
	bool com_sequential;
	bool color_inversion;
	bool sh1106_compatible;
	int ready_time_ms;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
};

struct ssd1306_data {
	uint8_t contrast;
	uint8_t scan_mode;
};

<<<<<<< HEAD
#if DT_INST_ON_BUS(0, i2c)

static inline bool ssd1306_bus_ready(const struct device *dev)
{
	const struct ssd1306_config *config = dev->config;

	return device_is_ready(config->bus.bus);
}

static inline int ssd1306_write_bus(const struct device *dev,
				    uint8_t *buf, size_t len, bool command)
{
	const struct ssd1306_config *config = dev->config;

	return i2c_burst_write_dt(&config->bus,
=======
#if (DT_HAS_COMPAT_ON_BUS_STATUS_OKAY(solomon_ssd1306fb, i2c) || \
	DT_HAS_COMPAT_ON_BUS_STATUS_OKAY(sinowealth_sh1106, i2c))
static bool ssd1306_bus_ready_i2c(const struct device *dev)
{
	const struct ssd1306_config *config = dev->config;

	return i2c_is_ready_dt(&config->bus.i2c);
}

static int ssd1306_write_bus_i2c(const struct device *dev, uint8_t *buf, size_t len, bool command)
{
	const struct ssd1306_config *config = dev->config;

	return i2c_burst_write_dt(&config->bus.i2c,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
				  command ? SSD1306_CONTROL_ALL_BYTES_CMD :
				  SSD1306_CONTROL_ALL_BYTES_DATA,
				  buf, len);
}

<<<<<<< HEAD
#elif DT_INST_ON_BUS(0, spi)

static inline bool ssd1306_bus_ready(const struct device *dev)
=======
static const char *ssd1306_bus_name_i2c(const struct device *dev)
{
	const struct ssd1306_config *config = dev->config;

	return config->bus.i2c.bus->name;
}
#endif

#if (DT_HAS_COMPAT_ON_BUS_STATUS_OKAY(solomon_ssd1306fb, spi) || \
	DT_HAS_COMPAT_ON_BUS_STATUS_OKAY(sinowealth_sh1106, spi))
static bool ssd1306_bus_ready_spi(const struct device *dev)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	const struct ssd1306_config *config = dev->config;

	if (gpio_pin_configure_dt(&config->data_cmd, GPIO_OUTPUT_INACTIVE) < 0) {
		return false;
	}

<<<<<<< HEAD
	return spi_is_ready_dt(&config->bus);
}

static inline int ssd1306_write_bus(const struct device *dev,
				    uint8_t *buf, size_t len, bool command)
=======
	return spi_is_ready_dt(&config->bus.spi);
}

static int ssd1306_write_bus_spi(const struct device *dev, uint8_t *buf, size_t len, bool command)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	const struct ssd1306_config *config = dev->config;
	int errno;

	gpio_pin_set_dt(&config->data_cmd, command ? 0 : 1);
	struct spi_buf tx_buf = {
		.buf = buf,
		.len = len
	};

	struct spi_buf_set tx_bufs = {
		.buffers = &tx_buf,
		.count = 1
	};

<<<<<<< HEAD
	errno = spi_write_dt(&config->bus, &tx_bufs);

	return errno;
}
#endif

static inline int ssd1306_set_panel_orientation(const struct device *dev)
{
	uint8_t cmd_buf[] = {
		(SSD1306_PANEL_SEGMENT_REMAP ?
		 SSD1306_SET_SEGMENT_MAP_REMAPED :
		 SSD1306_SET_SEGMENT_MAP_NORMAL),
		(SSD1306_PANEL_COM_INVDIR ?
		 SSD1306_SET_COM_OUTPUT_SCAN_FLIPPED :
		 SSD1306_SET_COM_OUTPUT_SCAN_NORMAL)
	};
=======
	errno = spi_write_dt(&config->bus.spi, &tx_bufs);

	return errno;
}

static const char *ssd1306_bus_name_spi(const struct device *dev)
{
	const struct ssd1306_config *config = dev->config;

	return config->bus.spi.bus->name;
}
#endif

static inline bool ssd1306_bus_ready(const struct device *dev)
{
	const struct ssd1306_config *config = dev->config;

	return config->bus_ready(dev);
}

static inline int ssd1306_write_bus(const struct device *dev, uint8_t *buf, size_t len,
				    bool command)
{
	const struct ssd1306_config *config = dev->config;

	return config->write_bus(dev, buf, len, command);
}

static inline int ssd1306_set_panel_orientation(const struct device *dev)
{
	const struct ssd1306_config *config = dev->config;
	uint8_t cmd_buf[] = {(config->segment_remap ? SSD1306_SET_SEGMENT_MAP_REMAPED
						    : SSD1306_SET_SEGMENT_MAP_NORMAL),
			     (config->com_invdir ? SSD1306_SET_COM_OUTPUT_SCAN_FLIPPED
						 : SSD1306_SET_COM_OUTPUT_SCAN_NORMAL)};
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	return ssd1306_write_bus(dev, cmd_buf, sizeof(cmd_buf), true);
}

static inline int ssd1306_set_timing_setting(const struct device *dev)
{
<<<<<<< HEAD
	uint8_t cmd_buf[] = {
		SSD1306_SET_CLOCK_DIV_RATIO,
		(SSD1306_CLOCK_FREQUENCY << 4) | SSD1306_CLOCK_DIV_RATIO,
		SSD1306_SET_CHARGE_PERIOD,
		DT_INST_PROP(0, prechargep),
		SSD1306_SET_VCOM_DESELECT_LEVEL,
		SSD1306_PANEL_VCOM_DESEL_LEVEL
	};
=======
	const struct ssd1306_config *config = dev->config;
	uint8_t cmd_buf[] = {SSD1306_SET_CLOCK_DIV_RATIO,
			     (SSD1306_CLOCK_FREQUENCY << 4) | SSD1306_CLOCK_DIV_RATIO,
			     SSD1306_SET_CHARGE_PERIOD,
			     config->prechargep,
			     SSD1306_SET_VCOM_DESELECT_LEVEL,
			     SSD1306_PANEL_VCOM_DESEL_LEVEL};
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	return ssd1306_write_bus(dev, cmd_buf, sizeof(cmd_buf), true);
}

static inline int ssd1306_set_hardware_config(const struct device *dev)
{
<<<<<<< HEAD
	uint8_t cmd_buf[] = {
		SSD1306_SET_START_LINE,
		SSD1306_SET_DISPLAY_OFFSET,
		DT_INST_PROP(0, display_offset),
		SSD1306_SET_PADS_HW_CONFIG,
		SSD1306_COM_PINS_HW_CONFIG,
		SSD1306_SET_MULTIPLEX_RATIO,
		DT_INST_PROP(0, multiplex_ratio)
=======
	const struct ssd1306_config *config = dev->config;
	uint8_t cmd_buf[] = {
		SSD1306_SET_START_LINE,
		SSD1306_SET_DISPLAY_OFFSET,
		config->display_offset,
		SSD1306_SET_PADS_HW_CONFIG,
		(config->com_sequential ? SSD1306_SET_PADS_HW_SEQUENTIAL
					: SSD1306_SET_PADS_HW_ALTERNATIVE),
		SSD1306_SET_MULTIPLEX_RATIO,
		config->multiplex_ratio,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	};

	return ssd1306_write_bus(dev, cmd_buf, sizeof(cmd_buf), true);
}

static inline int ssd1306_set_charge_pump(const struct device *dev)
{
<<<<<<< HEAD
	uint8_t cmd_buf[] = {
#if defined(CONFIG_SSD1306_DEFAULT)
		SSD1306_SET_CHARGE_PUMP_ON,
		SSD1306_SET_CHARGE_PUMP_ON_ENABLED,
#endif
#if defined(CONFIG_SSD1306_SH1106_COMPATIBLE)
		SH1106_SET_DCDC_MODE,
		SH1106_SET_DCDC_ENABLED,
#endif
=======
	const struct ssd1306_config *config = dev->config;
	uint8_t cmd_buf[] = {
		(config->sh1106_compatible ? SH1106_SET_DCDC_MODE : SSD1306_SET_CHARGE_PUMP_ON),
		(config->sh1106_compatible ? SH1106_SET_DCDC_ENABLED
					   : SSD1306_SET_CHARGE_PUMP_ON_ENABLED),
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		SSD1306_PANEL_PUMP_VOLTAGE,
	};

	return ssd1306_write_bus(dev, cmd_buf, sizeof(cmd_buf), true);
}

static int ssd1306_resume(const struct device *dev)
{
	uint8_t cmd_buf[] = {
		SSD1306_DISPLAY_ON,
	};

	return ssd1306_write_bus(dev, cmd_buf, sizeof(cmd_buf), true);
}

static int ssd1306_suspend(const struct device *dev)
{
	uint8_t cmd_buf[] = {
		SSD1306_DISPLAY_OFF,
	};

	return ssd1306_write_bus(dev, cmd_buf, sizeof(cmd_buf), true);
}

<<<<<<< HEAD
static int ssd1306_write(const struct device *dev, const uint16_t x, const uint16_t y,
			 const struct display_buffer_descriptor *desc,
			 const void *buf)
{
	size_t buf_len;

	if (desc->pitch < desc->width) {
		LOG_ERR("Pitch is smaller then width");
		return -1;
	}

	buf_len = MIN(desc->buf_size, desc->height * desc->width / 8);
	if (buf == NULL || buf_len == 0U) {
		LOG_ERR("Display buffer is not available");
		return -1;
	}

	if (desc->pitch > desc->width) {
		LOG_ERR("Unsupported mode");
		return -1;
	}

	if ((y & 0x7) != 0U) {
		LOG_ERR("Unsupported origin");
		return -1;
	}

	LOG_DBG("x %u, y %u, pitch %u, width %u, height %u, buf_len %u",
		x, y, desc->pitch, desc->width, desc->height, buf_len);

#if defined(CONFIG_SSD1306_DEFAULT)
=======
static int ssd1306_write_default(const struct device *dev, const uint16_t x, const uint16_t y,
				 const struct display_buffer_descriptor *desc, const void *buf,
				 const size_t buf_len)
{
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	uint8_t cmd_buf[] = {
		SSD1306_SET_MEM_ADDRESSING_MODE,
		SSD1306_ADDRESSING_MODE,
		SSD1306_SET_COLUMN_ADDRESS,
		x,
		(x + desc->width - 1),
		SSD1306_SET_PAGE_ADDRESS,
		y/8,
		((y + desc->height)/8 - 1)
	};

	if (ssd1306_write_bus(dev, cmd_buf, sizeof(cmd_buf), true)) {
		LOG_ERR("Failed to write command");
		return -1;
	}

	return ssd1306_write_bus(dev, (uint8_t *)buf, buf_len, false);
<<<<<<< HEAD

#elif defined(CONFIG_SSD1306_SH1106_COMPATIBLE)
	uint8_t x_offset = x + DT_INST_PROP(0, segment_offset);
=======
}

static int ssd1306_write_sh1106(const struct device *dev, const uint16_t x, const uint16_t y,
				const struct display_buffer_descriptor *desc, const void *buf,
				const size_t buf_len)
{
	const struct ssd1306_config *config = dev->config;
	uint8_t x_offset = x + config->segment_offset;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	uint8_t cmd_buf[] = {
		SSD1306_SET_LOWER_COL_ADDRESS |
			(x_offset & SSD1306_SET_LOWER_COL_ADDRESS_MASK),
		SSD1306_SET_HIGHER_COL_ADDRESS |
			((x_offset >> 4) & SSD1306_SET_LOWER_COL_ADDRESS_MASK),
		SSD1306_SET_PAGE_START_ADDRESS | (y / 8)
	};
	uint8_t *buf_ptr = (uint8_t *)buf;

	for (uint8_t n = 0; n < desc->height / 8; n++) {
		cmd_buf[sizeof(cmd_buf) - 1] =
			SSD1306_SET_PAGE_START_ADDRESS | (n + (y / 8));
		LOG_HEXDUMP_DBG(cmd_buf, sizeof(cmd_buf), "cmd_buf");

		if (ssd1306_write_bus(dev, cmd_buf, sizeof(cmd_buf), true)) {
			return -1;
		}

		if (ssd1306_write_bus(dev, buf_ptr, desc->width, false)) {
			return -1;
		}

		buf_ptr = buf_ptr + desc->width;
		if (buf_ptr > ((uint8_t *)buf + buf_len)) {
			LOG_ERR("Exceeded buffer length");
			return -1;
		}
	}
<<<<<<< HEAD
#endif
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	return 0;
}

<<<<<<< HEAD
=======
static int ssd1306_write(const struct device *dev, const uint16_t x, const uint16_t y,
			 const struct display_buffer_descriptor *desc, const void *buf)
{
	const struct ssd1306_config *config = dev->config;
	size_t buf_len;

	if (desc->pitch < desc->width) {
		LOG_ERR("Pitch is smaller then width");
		return -1;
	}

	buf_len = MIN(desc->buf_size, desc->height * desc->width / 8);
	if (buf == NULL || buf_len == 0U) {
		LOG_ERR("Display buffer is not available");
		return -1;
	}

	if (desc->pitch > desc->width) {
		LOG_ERR("Unsupported mode");
		return -1;
	}

	if ((y & 0x7) != 0U) {
		LOG_ERR("Unsupported origin");
		return -1;
	}

	LOG_DBG("x %u, y %u, pitch %u, width %u, height %u, buf_len %u", x, y, desc->pitch,
		desc->width, desc->height, buf_len);

	if (config->sh1106_compatible) {
		return ssd1306_write_sh1106(dev, x, y, desc, buf, buf_len);
	}

	return ssd1306_write_default(dev, x, y, desc, buf, buf_len);
}

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
static int ssd1306_read(const struct device *dev, const uint16_t x,
			const uint16_t y,
			const struct display_buffer_descriptor *desc,
			void *buf)
{
	LOG_ERR("Unsupported");
	return -ENOTSUP;
}

static void *ssd1306_get_framebuffer(const struct device *dev)
{
	LOG_ERR("Unsupported");
	return NULL;
}

static int ssd1306_set_brightness(const struct device *dev,
				  const uint8_t brightness)
{
	LOG_WRN("Unsupported");
	return -ENOTSUP;
}

static int ssd1306_set_contrast(const struct device *dev, const uint8_t contrast)
{
	uint8_t cmd_buf[] = {
		SSD1306_SET_CONTRAST_CTRL,
		contrast,
	};

	return ssd1306_write_bus(dev, cmd_buf, sizeof(cmd_buf), true);
}

static void ssd1306_get_capabilities(const struct device *dev,
				     struct display_capabilities *caps)
{
<<<<<<< HEAD
	memset(caps, 0, sizeof(struct display_capabilities));
	caps->x_resolution = DT_INST_PROP(0, width);
	caps->y_resolution = DT_INST_PROP(0, height);
=======
	const struct ssd1306_config *config = dev->config;
	memset(caps, 0, sizeof(struct display_capabilities));
	caps->x_resolution = config->width;
	caps->y_resolution = config->height;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	caps->supported_pixel_formats = PIXEL_FORMAT_MONO10;
	caps->current_pixel_format = PIXEL_FORMAT_MONO10;
	caps->screen_info = SCREEN_INFO_MONO_VTILED;
}

static int ssd1306_set_orientation(const struct device *dev,
				   const enum display_orientation
				   orientation)
{
	LOG_ERR("Unsupported");
	return -ENOTSUP;
}

static int ssd1306_set_pixel_format(const struct device *dev,
				    const enum display_pixel_format pf)
{
	if (pf == PIXEL_FORMAT_MONO10) {
		return 0;
	}
	LOG_ERR("Unsupported");
	return -ENOTSUP;
}

static int ssd1306_init_device(const struct device *dev)
{
	const struct ssd1306_config *config = dev->config;

	uint8_t cmd_buf[] = {
		SSD1306_SET_ENTIRE_DISPLAY_OFF,
<<<<<<< HEAD
#ifdef CONFIG_SSD1306_REVERSE_MODE
		SSD1306_SET_REVERSE_DISPLAY,
#else
		SSD1306_SET_NORMAL_DISPLAY,
#endif
=======
		(config->color_inversion ? SSD1306_SET_REVERSE_DISPLAY
					 : SSD1306_SET_NORMAL_DISPLAY),
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	};

	/* Reset if pin connected */
	if (config->reset.port) {
		k_sleep(K_MSEC(SSD1306_RESET_DELAY));
		gpio_pin_set_dt(&config->reset, 1);
		k_sleep(K_MSEC(SSD1306_RESET_DELAY));
		gpio_pin_set_dt(&config->reset, 0);
	}

	/* Turn display off */
	if (ssd1306_suspend(dev)) {
		return -EIO;
	}

	if (ssd1306_set_timing_setting(dev)) {
		return -EIO;
	}

	if (ssd1306_set_hardware_config(dev)) {
		return -EIO;
	}

	if (ssd1306_set_panel_orientation(dev)) {
		return -EIO;
	}

	if (ssd1306_set_charge_pump(dev)) {
		return -EIO;
	}

	if (ssd1306_write_bus(dev, cmd_buf, sizeof(cmd_buf), true)) {
		return -EIO;
	}

	if (ssd1306_set_contrast(dev, CONFIG_SSD1306_DEFAULT_CONTRAST)) {
		return -EIO;
	}

	ssd1306_resume(dev);

	return 0;
}

static int ssd1306_init(const struct device *dev)
{
	const struct ssd1306_config *config = dev->config;

	LOG_DBG("");

<<<<<<< HEAD
	if (!ssd1306_bus_ready(dev)) {
		LOG_ERR("Bus device %s not ready!", config->bus.bus->name);
=======
	k_sleep(K_TIMEOUT_ABS_MS(config->ready_time_ms));

	if (!ssd1306_bus_ready(dev)) {
		LOG_ERR("Bus device %s not ready!", config->bus_name(dev));
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		return -EINVAL;
	}

	if (config->reset.port) {
		int ret;

		ret = gpio_pin_configure_dt(&config->reset,
					    GPIO_OUTPUT_INACTIVE);
		if (ret < 0) {
			return ret;
		}
	}

	if (ssd1306_init_device(dev)) {
		LOG_ERR("Failed to initialize device!");
		return -EIO;
	}

	return 0;
}

<<<<<<< HEAD
static const struct ssd1306_config ssd1306_config = {
#if DT_INST_ON_BUS(0, i2c)
	.bus = I2C_DT_SPEC_INST_GET(0),
#elif DT_INST_ON_BUS(0, spi)
	.bus = SPI_DT_SPEC_INST_GET(
		0, SPI_OP_MODE_MASTER | SPI_TRANSFER_MSB | SPI_WORD_SET(8), 0),
	.data_cmd = GPIO_DT_SPEC_INST_GET(0, data_cmd_gpios),
#endif
	.reset = GPIO_DT_SPEC_INST_GET_OR(0, reset_gpios, { 0 })
};

static struct ssd1306_data ssd1306_driver;

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
static struct display_driver_api ssd1306_driver_api = {
	.blanking_on = ssd1306_suspend,
	.blanking_off = ssd1306_resume,
	.write = ssd1306_write,
	.read = ssd1306_read,
	.get_framebuffer = ssd1306_get_framebuffer,
	.set_brightness = ssd1306_set_brightness,
	.set_contrast = ssd1306_set_contrast,
	.get_capabilities = ssd1306_get_capabilities,
	.set_pixel_format = ssd1306_set_pixel_format,
	.set_orientation = ssd1306_set_orientation,
};

<<<<<<< HEAD
DEVICE_DT_INST_DEFINE(0, ssd1306_init, NULL,
		      &ssd1306_driver, &ssd1306_config,
		      POST_KERNEL, CONFIG_DISPLAY_INIT_PRIORITY,
		      &ssd1306_driver_api);
=======
#define SSD1306_CONFIG_SPI(node_id)                                                                \
	.bus = {.spi = SPI_DT_SPEC_GET(                                                            \
			node_id, SPI_OP_MODE_MASTER | SPI_TRANSFER_MSB | SPI_WORD_SET(8), 0)},     \
	.bus_ready = ssd1306_bus_ready_spi,                                                        \
	.write_bus = ssd1306_write_bus_spi,                                                        \
	.bus_name = ssd1306_bus_name_spi,                                                          \
	.data_cmd = GPIO_DT_SPEC_GET(node_id, data_cmd_gpios),

#define SSD1306_CONFIG_I2C(node_id)                                                                \
	.bus = {.i2c = I2C_DT_SPEC_GET(node_id)},                                                  \
	.bus_ready = ssd1306_bus_ready_i2c,                                                        \
	.write_bus = ssd1306_write_bus_i2c,                                                        \
	.bus_name = ssd1306_bus_name_i2c,                                                          \
	.data_cmd = {0},

#define SSD1306_DEFINE(node_id)                                                                    \
	static struct ssd1306_data data##node_id;                                                  \
	static const struct ssd1306_config config##node_id = {                                     \
		.reset = GPIO_DT_SPEC_GET_OR(node_id, reset_gpios, {0}),                           \
		.height = DT_PROP(node_id, height),                                                \
		.width = DT_PROP(node_id, width),                                                  \
		.segment_offset = DT_PROP(node_id, segment_offset),                                \
		.page_offset = DT_PROP(node_id, page_offset),                                      \
		.display_offset = DT_PROP(node_id, display_offset),                                \
		.multiplex_ratio = DT_PROP(node_id, multiplex_ratio),                              \
		.segment_remap = DT_PROP(node_id, segment_remap),                                  \
		.com_invdir = DT_PROP(node_id, com_invdir),                                        \
		.com_sequential = DT_PROP(node_id, com_sequential),                                \
		.prechargep = DT_PROP(node_id, prechargep),                                        \
		.color_inversion = DT_PROP(node_id, inversion_on),                                 \
		.sh1106_compatible = DT_NODE_HAS_COMPAT(node_id, sinowealth_sh1106),               \
		.ready_time_ms = DT_PROP(node_id, ready_time_ms),                                  \
		COND_CODE_1(DT_ON_BUS(node_id, spi), (SSD1306_CONFIG_SPI(node_id)),                \
			    (SSD1306_CONFIG_I2C(node_id)))                                         \
	};                                                                                         \
                                                                                                   \
	DEVICE_DT_DEFINE(node_id, ssd1306_init, NULL, &data##node_id, &config##node_id,            \
			 POST_KERNEL, CONFIG_DISPLAY_INIT_PRIORITY, &ssd1306_driver_api);

DT_FOREACH_STATUS_OKAY(solomon_ssd1306fb, SSD1306_DEFINE)
DT_FOREACH_STATUS_OKAY(sinowealth_sh1106, SSD1306_DEFINE)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
