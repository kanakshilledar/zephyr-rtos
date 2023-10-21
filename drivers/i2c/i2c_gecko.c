/*
 * Copyright (c) 2018 Diego Sueiro
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT silabs_gecko_i2c

#include <errno.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <em_cmu.h>
#include <em_i2c.h>
#include <em_gpio.h>
#include <soc.h>

#define LOG_LEVEL CONFIG_I2C_LOG_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(i2c_gecko);

#include "i2c-priv.h"

<<<<<<< HEAD
#define DEV_BASE(dev) \
	((I2C_TypeDef *)((const struct i2c_gecko_config * const)(dev)->config)->base)
=======
#define DEV_BASE(dev) ((I2C_TypeDef *)((const struct i2c_gecko_config *const)(dev)->config)->base)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

struct i2c_gecko_config {
	I2C_TypeDef *base;
	CMU_Clock_TypeDef clock;
	uint32_t bitrate;
	struct soc_gpio_pin pin_sda;
	struct soc_gpio_pin pin_scl;
#ifdef CONFIG_SOC_GECKO_HAS_INDIVIDUAL_PIN_LOCATION
	uint8_t loc_sda;
	uint8_t loc_scl;
#else
	uint8_t loc;
#endif
<<<<<<< HEAD
=======
#if defined(CONFIG_I2C_TARGET)
	void (*irq_config_func)(const struct device *dev);
#endif
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
};

struct i2c_gecko_data {
	struct k_sem device_sync_sem;
	uint32_t dev_config;
<<<<<<< HEAD
};

void i2c_gecko_config_pins(const struct device *dev,
			   const struct soc_gpio_pin *pin_sda,
=======
#if defined(CONFIG_I2C_TARGET)
	struct i2c_target_config *target_cfg;
#endif
};

void i2c_gecko_config_pins(const struct device *dev, const struct soc_gpio_pin *pin_sda,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			   const struct soc_gpio_pin *pin_scl)
{
	I2C_TypeDef *base = DEV_BASE(dev);
	const struct i2c_gecko_config *config = dev->config;

	GPIO_PinModeSet(pin_scl->port, pin_scl->pin, pin_scl->mode, pin_scl->out);
	GPIO_PinModeSet(pin_sda->port, pin_sda->pin, pin_sda->mode, pin_sda->out);

#ifdef CONFIG_SOC_GECKO_HAS_INDIVIDUAL_PIN_LOCATION
	base->ROUTEPEN = I2C_ROUTEPEN_SDAPEN | I2C_ROUTEPEN_SCLPEN;
	base->ROUTELOC0 = (config->loc_sda << _I2C_ROUTELOC0_SDALOC_SHIFT) |
			  (config->loc_scl << _I2C_ROUTELOC0_SCLLOC_SHIFT);
#elif defined(GPIO_I2C_ROUTEEN_SCLPEN) && defined(GPIO_I2C_ROUTEEN_SDAPEN)
<<<<<<< HEAD
	GPIO->I2CROUTE[I2C_NUM(base)].ROUTEEN = GPIO_I2C_ROUTEEN_SCLPEN |
		GPIO_I2C_ROUTEEN_SDAPEN;
=======
	GPIO->I2CROUTE[I2C_NUM(base)].ROUTEEN = GPIO_I2C_ROUTEEN_SCLPEN | GPIO_I2C_ROUTEEN_SDAPEN;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	GPIO->I2CROUTE[I2C_NUM(base)].SCLROUTE =
		(config->pin_scl.pin << _GPIO_I2C_SCLROUTE_PIN_SHIFT) |
		(config->pin_scl.port << _GPIO_I2C_SCLROUTE_PORT_SHIFT);
	GPIO->I2CROUTE[I2C_NUM(base)].SDAROUTE =
		(config->pin_sda.pin << _GPIO_I2C_SDAROUTE_PIN_SHIFT) |
		(config->pin_sda.port << _GPIO_I2C_SDAROUTE_PORT_SHIFT);
#else
	base->ROUTE = I2C_ROUTE_SDAPEN | I2C_ROUTE_SCLPEN | (config->loc << 8);
#endif
}

<<<<<<< HEAD
static int i2c_gecko_configure(const struct device *dev,
			       uint32_t dev_config_raw)
=======
static int i2c_gecko_configure(const struct device *dev, uint32_t dev_config_raw)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	I2C_TypeDef *base = DEV_BASE(dev);
	struct i2c_gecko_data *data = dev->data;
	I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
	uint32_t baudrate;

	if (!(I2C_MODE_CONTROLLER & dev_config_raw)) {
		return -EINVAL;
	}

	switch (I2C_SPEED_GET(dev_config_raw)) {
	case I2C_SPEED_STANDARD:
		baudrate = KHZ(100);
		break;
	case I2C_SPEED_FAST:
		baudrate = KHZ(400);
		break;
	case I2C_SPEED_FAST_PLUS:
		baudrate = MHZ(1);
		break;
	default:
		return -EINVAL;
	}

	data->dev_config = dev_config_raw;
	i2cInit.freq = baudrate;

<<<<<<< HEAD
=======
#if defined(CONFIG_I2C_TARGET)
	i2cInit.master = 0;
#endif

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	I2C_Init(base, &i2cInit);

	return 0;
}

<<<<<<< HEAD
static int i2c_gecko_transfer(const struct device *dev, struct i2c_msg *msgs,
			      uint8_t num_msgs, uint16_t addr)
=======
static int i2c_gecko_transfer(const struct device *dev, struct i2c_msg *msgs, uint8_t num_msgs,
			      uint16_t addr)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	I2C_TypeDef *base = DEV_BASE(dev);
	struct i2c_gecko_data *data = dev->data;
	I2C_TransferSeq_TypeDef seq;
	I2C_TransferReturn_TypeDef ret = -EIO;
	uint32_t timeout = 300000U;

	if (!num_msgs) {
		return 0;
	}

	seq.addr = addr << 1;

	do {
		seq.buf[0].data = msgs->buf;
<<<<<<< HEAD
		seq.buf[0].len	= msgs->len;
=======
		seq.buf[0].len = msgs->len;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

		if ((msgs->flags & I2C_MSG_RW_MASK) == I2C_MSG_READ) {
			seq.flags = I2C_FLAG_READ;
		} else {
			seq.flags = I2C_FLAG_WRITE;
			if (num_msgs > 1) {
				/* Next message */
				msgs++;
				num_msgs--;
<<<<<<< HEAD
				if ((msgs->flags & I2C_MSG_RW_MASK)
				    == I2C_MSG_READ) {
=======
				if ((msgs->flags & I2C_MSG_RW_MASK) == I2C_MSG_READ) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
					seq.flags = I2C_FLAG_WRITE_READ;
				} else {
					seq.flags = I2C_FLAG_WRITE_WRITE;
				}
				seq.buf[1].data = msgs->buf;
<<<<<<< HEAD
				seq.buf[1].len	= msgs->len;
=======
				seq.buf[1].len = msgs->len;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			}
		}

		if (data->dev_config & I2C_ADDR_10_BITS) {
			seq.flags |= I2C_FLAG_10BIT_ADDR;
		}

		/* Do a polled transfer */
		ret = I2C_TransferInit(base, &seq);
		while (ret == i2cTransferInProgress && timeout--) {
			ret = I2C_Transfer(base);
		}

		if (ret != i2cTransferDone) {
			goto finish;
		}

		/* Next message */
		msgs++;
		num_msgs--;
	} while (num_msgs);

finish:
	if (ret != i2cTransferDone) {
		ret = -EIO;
	}
	return ret;
}

static int i2c_gecko_init(const struct device *dev)
{
	const struct i2c_gecko_config *config = dev->config;
	uint32_t bitrate_cfg;
	int error;

	CMU_ClockEnable(config->clock, true);

	i2c_gecko_config_pins(dev, &config->pin_sda, &config->pin_scl);

	bitrate_cfg = i2c_map_dt_bitrate(config->bitrate);

	error = i2c_gecko_configure(dev, I2C_MODE_CONTROLLER | bitrate_cfg);
	if (error) {
		return error;
	}

	return 0;
}

<<<<<<< HEAD
static const struct i2c_driver_api i2c_gecko_driver_api = {
	.configure = i2c_gecko_configure,
	.transfer = i2c_gecko_transfer,
};

#ifdef CONFIG_SOC_GECKO_HAS_INDIVIDUAL_PIN_LOCATION
#define I2C_LOC_DATA(idx) \
	.loc_sda = DT_INST_PROP_BY_IDX(idx, location_sda, 0), \
	.loc_scl = DT_INST_PROP_BY_IDX(idx, location_scl, 0)
#define I2C_VALIDATE_LOC(idx) BUILD_ASSERT(true, "")
#else
#define I2C_VALIDATE_LOC(idx) \
	BUILD_ASSERT(DT_INST_PROP_BY_IDX(idx, location_sda, 0) \
		     == DT_INST_PROP_BY_IDX(idx, location_scl, 0), \
		     "DTS location-* properties must be equal")
#define I2C_LOC_DATA(idx) \
	.loc = DT_INST_PROP_BY_IDX(idx, location_scl, 0)
#endif

#define I2C_INIT(idx) \
I2C_VALIDATE_LOC(idx); \
static const struct i2c_gecko_config i2c_gecko_config_##idx = { \
	.base = (I2C_TypeDef *)DT_INST_REG_ADDR(idx), \
	.clock = cmuClock_I2C##idx, \
	.pin_sda = {DT_INST_PROP_BY_IDX(idx, location_sda, 1), \
		DT_INST_PROP_BY_IDX(idx, location_sda, 2), gpioModeWiredAnd, 1}, \
	.pin_scl = {DT_INST_PROP_BY_IDX(idx, location_scl, 1), \
		DT_INST_PROP_BY_IDX(idx, location_scl, 2), gpioModeWiredAnd, 1}, \
	I2C_LOC_DATA(idx), \
	.bitrate = DT_INST_PROP(idx, clock_frequency), \
}; \
\
static struct i2c_gecko_data i2c_gecko_data_##idx; \
\
I2C_DEVICE_DT_INST_DEFINE(idx, i2c_gecko_init, \
		 NULL, \
		 &i2c_gecko_data_##idx, &i2c_gecko_config_##idx, \
		 POST_KERNEL, CONFIG_I2C_INIT_PRIORITY, \
		 &i2c_gecko_driver_api);
=======
#if defined(CONFIG_I2C_TARGET)
static int i2c_gecko_target_register(const struct device *dev, struct i2c_target_config *cfg)
{
	const struct i2c_gecko_config *config = dev->config;
	struct i2c_gecko_data *data = dev->data;

	data->target_cfg = cfg;

	I2C_SlaveAddressSet(config->base, cfg->address << _I2C_SADDR_ADDR_SHIFT);
	/* Match with specified address, no wildcards in address */
	I2C_SlaveAddressMaskSet(config->base, _I2C_SADDRMASK_SADDRMASK_MASK);

	I2C_IntDisable(config->base, _I2C_IEN_MASK);
	I2C_IntEnable(config->base, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_ACK | I2C_IEN_SSTOP |
					    I2C_IEN_BUSERR | I2C_IEN_ARBLOST);

	config->irq_config_func(dev);

	return 0;
}

static int i2c_gecko_target_unregister(const struct device *dev, struct i2c_target_config *cfg)
{
	const struct i2c_gecko_config *config = dev->config;
	struct i2c_gecko_data *data = dev->data;

	data->target_cfg = NULL;

	I2C_IntDisable(config->base, _I2C_IEN_MASK);

	return 0;
}
#endif

static const struct i2c_driver_api i2c_gecko_driver_api = {
	.configure = i2c_gecko_configure,
	.transfer = i2c_gecko_transfer,
#if defined(CONFIG_I2C_TARGET)
	.target_register = i2c_gecko_target_register,
	.target_unregister = i2c_gecko_target_unregister,
#endif
};

#if defined(CONFIG_I2C_TARGET)
void i2c_gecko_isr(const struct device *dev)
{
	const struct i2c_gecko_config *config = dev->config;
	struct i2c_gecko_data *data = dev->data;

	uint32_t pending;
	uint32_t rx_byte;
	uint8_t tx_byte;

	pending = config->base->IF;

	/* If some sort of fault, abort transfer. */
	if (pending & (I2C_IF_BUSERR | I2C_IF_ARBLOST)) {
		LOG_ERR("I2C Bus Error");
		I2C_IntClear(config->base, I2C_IF_BUSERR);
		I2C_IntClear(config->base, I2C_IF_ARBLOST);
	} else {
		if (pending & I2C_IF_ADDR) {
			/* Address Match, indicating that reception is started */
			rx_byte = config->base->RXDATA;
			config->base->CMD = I2C_CMD_ACK;

			/* Check if read bit set */
			if (rx_byte & 0x1) {
				data->target_cfg->callbacks->read_requested(data->target_cfg,
									    &tx_byte);
				config->base->TXDATA = tx_byte;
			} else {
				data->target_cfg->callbacks->write_requested(data->target_cfg);
			}

			I2C_IntClear(config->base, I2C_IF_ADDR | I2C_IF_RXDATAV);
		} else if (pending & I2C_IF_RXDATAV) {
			rx_byte = config->base->RXDATA;
			/* Read new data and write to target address */
			data->target_cfg->callbacks->write_received(data->target_cfg, rx_byte);
			config->base->CMD = I2C_CMD_ACK;

			I2C_IntClear(config->base, I2C_IF_RXDATAV);
		}

		if (pending & I2C_IF_ACK) {
			/* Leader ACK'ed, so requesting more data */
			data->target_cfg->callbacks->read_processed(data->target_cfg, &tx_byte);
			config->base->TXDATA = tx_byte;

			I2C_IntClear(config->base, I2C_IF_ACK);
		}

		if (pending & I2C_IF_SSTOP) {
			/* End of transaction */
			data->target_cfg->callbacks->stop(data->target_cfg);
			I2C_IntClear(config->base, I2C_IF_SSTOP);
		}
	}
}
#endif

#ifdef CONFIG_SOC_GECKO_HAS_INDIVIDUAL_PIN_LOCATION
#define I2C_LOC_DATA(idx)                                                                          \
	.loc_sda = DT_INST_PROP_BY_IDX(idx, location_sda, 0),                                      \
	.loc_scl = DT_INST_PROP_BY_IDX(idx, location_scl, 0)
#define I2C_VALIDATE_LOC(idx) BUILD_ASSERT(true, "")
#else
#define I2C_VALIDATE_LOC(idx)                                                                      \
	BUILD_ASSERT(DT_INST_PROP_BY_IDX(idx, location_sda, 0) ==                                  \
			     DT_INST_PROP_BY_IDX(idx, location_scl, 0),                            \
		     "DTS location-* properties must be equal")
#define I2C_LOC_DATA(idx) .loc = DT_INST_PROP_BY_IDX(idx, location_scl, 0)
#endif

#if defined(CONFIG_I2C_TARGET)
#define GECKO_I2C_IRQ_DEF(idx)  static void i2c_gecko_config_func_##idx(const struct device *dev);
#define GECKO_I2C_IRQ_DATA(idx) .irq_config_func = i2c_gecko_config_func_##idx,
#define GECKO_I2C_IRQ_HANDLER(idx)                                                                 \
	static void i2c_gecko_config_func_##idx(const struct device *dev)                          \
	{                                                                                          \
		IRQ_CONNECT(DT_INST_IRQ(idx, irq), DT_INST_IRQ(idx, priority), i2c_gecko_isr,      \
			    DEVICE_DT_INST_GET(idx), 0);                                           \
		irq_enable(DT_INST_IRQ(idx, irq));                                                 \
	}
#else
#define GECKO_I2C_IRQ_HANDLER(idx)
#define GECKO_I2C_IRQ_DEF(idx)
#define GECKO_I2C_IRQ_DATA(idx)
#endif

#define I2C_INIT(idx)                                                                              \
	I2C_VALIDATE_LOC(idx);                                                                     \
	GECKO_I2C_IRQ_DEF(idx)                                                                     \
	static const struct i2c_gecko_config i2c_gecko_config_##idx = {                            \
		.base = (I2C_TypeDef *)DT_INST_REG_ADDR(idx),                                      \
		.clock = cmuClock_I2C##idx,                                                        \
		.pin_sda = {DT_INST_PROP_BY_IDX(idx, location_sda, 1),                             \
			    DT_INST_PROP_BY_IDX(idx, location_sda, 2), gpioModeWiredAnd, 1},       \
		.pin_scl = {DT_INST_PROP_BY_IDX(idx, location_scl, 1),                             \
			    DT_INST_PROP_BY_IDX(idx, location_scl, 2), gpioModeWiredAnd, 1},       \
		I2C_LOC_DATA(idx),                                                                 \
		.bitrate = DT_INST_PROP(idx, clock_frequency),                                     \
		GECKO_I2C_IRQ_DATA(idx)};                                                          \
	static struct i2c_gecko_data i2c_gecko_data_##idx;                                         \
	I2C_DEVICE_DT_INST_DEFINE(idx, i2c_gecko_init, NULL, &i2c_gecko_data_##idx,                \
				  &i2c_gecko_config_##idx, POST_KERNEL, CONFIG_I2C_INIT_PRIORITY,  \
				  &i2c_gecko_driver_api);                                          \
	GECKO_I2C_IRQ_HANDLER(idx)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

DT_INST_FOREACH_STATUS_OKAY(I2C_INIT)
