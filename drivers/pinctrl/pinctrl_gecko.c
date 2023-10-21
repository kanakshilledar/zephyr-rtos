/*
<<<<<<< HEAD
 * Copyright (c) 2022 Silicon Labs
=======
 * Copyright (c) 2023 Silicon Labs
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/drivers/pinctrl.h>

#include <soc_gpio.h>

int pinctrl_configure_pins(const pinctrl_soc_pin_t *pins, uint8_t pin_cnt, uintptr_t reg)
{
	USART_TypeDef *base = (USART_TypeDef *)reg;
<<<<<<< HEAD
	int usart_num = USART_NUM(base);
	uint8_t loc;

#ifdef CONFIG_SPI_GECKO
	struct soc_gpio_pin spi_pin_cfg = {0, 0, 0, 0};
#endif /* CONFIG_SPI_GECKO */
=======
	uint8_t loc;
#ifdef CONFIG_SOC_GECKO_SERIES1
	LEUART_TypeDef *lebase = (LEUART_TypeDef *)reg;
#else
	int usart_num = USART_NUM(base);
#endif
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#ifdef CONFIG_UART_GECKO
	struct soc_gpio_pin rxpin = {0, 0, 0, 0};
	struct soc_gpio_pin txpin = {0, 0, 0, 0};
#endif /* CONFIG_UART_GECKO */

<<<<<<< HEAD
	for (uint8_t i = 0U; i < pin_cnt; i++) {
=======
	struct soc_gpio_pin pin_config = {0, 0, 0, 0};

	for (uint8_t i = 0U; i < pin_cnt; i++) {
		pin_config.port = GECKO_GET_PORT(pins[i]);
		pin_config.pin = GECKO_GET_PIN(pins[i]);
		loc = GECKO_GET_LOC(pins[i]);

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		switch (GECKO_GET_FUN(pins[i])) {
#ifdef CONFIG_UART_GECKO
		case GECKO_FUN_UART_RX:
			rxpin.port = GECKO_GET_PORT(pins[i]);
			rxpin.pin = GECKO_GET_PIN(pins[i]);
			rxpin.mode = gpioModeInput;
			rxpin.out = 1;
			GPIO_PinModeSet(rxpin.port, rxpin.pin, rxpin.mode,
<<<<<<< HEAD
							       rxpin.out);
			break;
=======
					rxpin.out);
			break;

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		case GECKO_FUN_UART_TX:
			txpin.port = GECKO_GET_PORT(pins[i]);
			txpin.pin = GECKO_GET_PIN(pins[i]);
			txpin.mode = gpioModePushPull;
			txpin.out = 1;
			GPIO_PinModeSet(txpin.port, txpin.pin, txpin.mode,
<<<<<<< HEAD
							       txpin.out);
			break;
		case GECKO_FUN_UART_LOC:
			loc = GECKO_GET_LOC(pins[i]);
=======
					txpin.out);
			break;

#ifdef CONFIG_SOC_GECKO_SERIES1
		case GECKO_FUN_UART_RTS:
			pin_config.mode = gpioModePushPull;
			pin_config.out = 1;
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_UART_CTS:
			pin_config.mode = gpioModeInput;
			pin_config.out = 1;
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_UART_RX_LOC:
			base->ROUTEPEN |= USART_ROUTEPEN_RXPEN;
			base->ROUTELOC0 &= ~_USART_ROUTELOC0_RXLOC_MASK;
			base->ROUTELOC0 |= (loc << _USART_ROUTELOC0_RXLOC_SHIFT);
			break;

		case GECKO_FUN_UART_TX_LOC:
			base->ROUTEPEN |= USART_ROUTEPEN_TXPEN;
			base->ROUTELOC0 &= ~_USART_ROUTELOC0_TXLOC_MASK;
			base->ROUTELOC0 |= (loc << _USART_ROUTELOC0_TXLOC_SHIFT);
			break;

		case GECKO_FUN_UART_RTS_LOC:
			base->ROUTEPEN |= USART_ROUTEPEN_RTSPEN;
			base->ROUTELOC1 &= ~_USART_ROUTELOC1_RTSLOC_MASK;
			base->ROUTELOC1 |= (loc << _USART_ROUTELOC1_RTSLOC_SHIFT);
			break;

		case GECKO_FUN_UART_CTS_LOC:
			base->ROUTEPEN |= USART_ROUTEPEN_CTSPEN;
			base->ROUTELOC1 &= ~_USART_ROUTELOC1_CTSLOC_MASK;
			base->ROUTELOC1 |= (loc << _USART_ROUTELOC1_CTSLOC_SHIFT);
			break;

		case GECKO_FUN_LEUART_RX_LOC:
			lebase->ROUTEPEN |= LEUART_ROUTEPEN_RXPEN;
			lebase->ROUTELOC0 &= ~_LEUART_ROUTELOC0_RXLOC_MASK;
			lebase->ROUTELOC0 |= (loc << _LEUART_ROUTELOC0_RXLOC_SHIFT);
			break;

		case GECKO_FUN_LEUART_TX_LOC:
			lebase->ROUTEPEN |= LEUART_ROUTEPEN_TXPEN;
			lebase->ROUTELOC0 &= ~_LEUART_ROUTELOC0_TXLOC_MASK;
			lebase->ROUTELOC0 |= (loc << _LEUART_ROUTELOC0_TXLOC_SHIFT);
			break;
#else /* CONFIG_SOC_GECKO_SERIES1 */
		case GECKO_FUN_UART_LOC:
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#ifdef CONFIG_SOC_GECKO_HAS_INDIVIDUAL_PIN_LOCATION
			/* For SOCs with configurable pin_cfg locations (set in SOC Kconfig) */
			base->ROUTEPEN = USART_ROUTEPEN_RXPEN | USART_ROUTEPEN_TXPEN;
			base->ROUTELOC0 = (loc << _USART_ROUTELOC0_TXLOC_SHIFT) |
					  (loc << _USART_ROUTELOC0_RXLOC_SHIFT);
			base->ROUTELOC1 = _USART_ROUTELOC1_RESETVALUE;
#elif defined(USART_ROUTE_RXPEN) && defined(USART_ROUTE_TXPEN)
			/* For olders SOCs with only one pin location */
			base->ROUTE = USART_ROUTE_RXPEN | USART_ROUTE_TXPEN | (loc << 8);
#elif defined(GPIO_USART_ROUTEEN_RXPEN) && defined(GPIO_USART_ROUTEEN_TXPEN)
			GPIO->USARTROUTE[usart_num].ROUTEEN =
				GPIO_USART_ROUTEEN_TXPEN | GPIO_USART_ROUTEEN_RXPEN;
			GPIO->USARTROUTE[usart_num].TXROUTE =
				(txpin.pin << _GPIO_USART_TXROUTE_PIN_SHIFT) |
				(txpin.port << _GPIO_USART_TXROUTE_PORT_SHIFT);
			GPIO->USARTROUTE[usart_num].RXROUTE =
				(rxpin.pin << _GPIO_USART_RXROUTE_PIN_SHIFT) |
				(rxpin.port << _GPIO_USART_RXROUTE_PORT_SHIFT);
#endif /* CONFIG_SOC_GECKO_HAS_INDIVIDUAL_PIN_LOCATION */

#ifdef UART_GECKO_HW_FLOW_CONTROL
			/* Configure HW flow control (RTS, CTS) */
			if (config->hw_flowcontrol) {
				GPIO_PinModeSet(config->pin_rts.port,
						 config->pin_rts.pin,
						 config->pin_rts.mode,
						 config->pin_rts.out);
				GPIO_PinModeSet(config->pin_cts.port,
						 config->pin_cts.pin,
						 config->pin_cts.mode,
						 config->pin_cts.out);
#ifdef CONFIG_SOC_GECKO_HAS_INDIVIDUAL_PIN_LOCATION
				config->base->ROUTEPEN =
					USART_ROUTEPEN_RXPEN | USART_ROUTEPEN_TXPEN |
					USART_ROUTEPEN_RTSPEN | USART_ROUTEPEN_CTSPEN;

				config->base->ROUTELOC1 =
					(config->loc_rts << _USART_ROUTELOC1_RTSLOC_SHIFT) |
					(config->loc_cts << _USART_ROUTELOC1_CTSLOC_SHIFT);
#elif defined(GPIO_USART_ROUTEEN_RTSPEN) && defined(GPIO_USART_ROUTEEN_CTSPEN)
				GPIO->USARTROUTE[usart_num].ROUTEEN =
					GPIO_USART_ROUTEEN_TXPEN | GPIO_USART_ROUTEEN_RXPEN |
					GPIO_USART_ROUTEPEN_RTSPEN | GPIO_USART_ROUTEPEN_CTSPEN;

				GPIO->USARTROUTE[usart_num].RTSROUTE =
					(config->pin_rts.pin << _GPIO_USART_RTSROUTE_PIN_SHIFT) |
					(config->pin_rts.port << _GPIO_USART_RTSROUTE_PORT_SHIFT);
				GPIO->USARTROUTE[usart_num].CTSROUTE =
					(config->pin_cts.pin << _GPIO_USART_CTSROUTE_PIN_SHIFT) |
					(config->pin_cts.port << _GPIO_USART_CTSROUTE_PORT_SHIFT);
#endif /* CONFIG_SOC_GECKO_HAS_INDIVIDUAL_PIN_LOCATION */
			}
#endif /* UART_GECKO_HW_FLOW_CONTROL */
			break;
<<<<<<< HEAD
#endif /* CONFIG_UART_GECKO */
#ifdef CONFIG_SPI_GECKO
		case GECKO_FUN_SPI_SCK:
			spi_pin_cfg.port = GECKO_GET_PORT(pins[i]);
			spi_pin_cfg.pin = GECKO_GET_PIN(pins[i]);
			spi_pin_cfg.mode = gpioModePushPull;
			spi_pin_cfg.out = 1;
			GPIO->USARTROUTE[usart_num].ROUTEEN |= GPIO_USART_ROUTEEN_CLKPEN;
			GPIO->USARTROUTE[usart_num].CLKROUTE =
				(spi_pin_cfg.pin << _GPIO_USART_CLKROUTE_PIN_SHIFT) |
				(spi_pin_cfg.port << _GPIO_USART_CLKROUTE_PORT_SHIFT);
			break;
		case GECKO_FUN_SPI_MOSI:
			spi_pin_cfg.port = GECKO_GET_PORT(pins[i]);
			spi_pin_cfg.pin = GECKO_GET_PIN(pins[i]);
			spi_pin_cfg.mode = gpioModePushPull;
			spi_pin_cfg.out = 1;
			GPIO->USARTROUTE[usart_num].ROUTEEN |= GPIO_USART_ROUTEEN_TXPEN;
			GPIO->USARTROUTE[usart_num].TXROUTE =
				(spi_pin_cfg.pin << _GPIO_USART_TXROUTE_PIN_SHIFT) |
				(spi_pin_cfg.port << _GPIO_USART_TXROUTE_PORT_SHIFT);
			break;
		case GECKO_FUN_SPI_MISO:
			spi_pin_cfg.port = GECKO_GET_PORT(pins[i]);
			spi_pin_cfg.pin = GECKO_GET_PIN(pins[i]);
			spi_pin_cfg.mode = gpioModeInput;
			spi_pin_cfg.out = 1;
			GPIO->USARTROUTE[usart_num].ROUTEEN |= GPIO_USART_ROUTEEN_RXPEN;
			GPIO->USARTROUTE[usart_num].RXROUTE =
				(spi_pin_cfg.pin << _GPIO_USART_RXROUTE_PIN_SHIFT) |
				(spi_pin_cfg.port << _GPIO_USART_RXROUTE_PORT_SHIFT);
			break;
=======
#endif /* CONFIG_SOC_GECKO_SERIES1 */
#endif /* CONFIG_UART_GECKO */

#ifdef CONFIG_SPI_GECKO
#ifdef CONFIG_SOC_GECKO_SERIES1
		case GECKO_FUN_SPIM_SCK:
			pin_config.mode = gpioModePushPull;
			pin_config.out = 1;
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_SPIM_MOSI:
			pin_config.mode = gpioModePushPull;
			pin_config.out = 1;
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_SPIM_MISO:
			pin_config.mode = gpioModeInput;
			pin_config.out = 1;
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_SPIM_CS:
			pin_config.mode = gpioModePushPull;
			pin_config.out = 1;
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_SPIS_SCK:
			pin_config.mode = gpioModeInput;
			pin_config.out = 1;
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_SPIS_MOSI:
			pin_config.mode = gpioModeInput;
			pin_config.out = 1;
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_SPIS_MISO:
			pin_config.mode = gpioModePushPull;
			pin_config.out = 1;
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_SPIS_CS:
			pin_config.mode = gpioModeInput;
			pin_config.out = 1;
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_SPI_SCK_LOC:
			base->ROUTEPEN |= USART_ROUTEPEN_CLKPEN;
			base->ROUTELOC0 &= ~_USART_ROUTELOC0_CLKLOC_MASK;
			base->ROUTELOC0 |= (loc << _USART_ROUTELOC0_CLKLOC_SHIFT);
			break;

		case GECKO_FUN_SPI_MOSI_LOC:
			base->ROUTEPEN |= USART_ROUTEPEN_TXPEN;
			base->ROUTELOC0 &= ~_USART_ROUTELOC0_TXLOC_MASK;
			base->ROUTELOC0 |= (loc << _USART_ROUTELOC0_TXLOC_SHIFT);
			break;

		case GECKO_FUN_SPI_MISO_LOC:
			base->ROUTEPEN |= USART_ROUTEPEN_RXPEN;
			base->ROUTELOC0 &= ~_USART_ROUTELOC0_RXLOC_MASK;
			base->ROUTELOC0 |= (loc << _USART_ROUTELOC0_RXLOC_SHIFT);
			break;

		case GECKO_FUN_SPI_CS_LOC:
			base->ROUTEPEN |= USART_ROUTEPEN_CSPEN;
			base->ROUTELOC0 &= ~_USART_ROUTELOC0_CSLOC_MASK;
			base->ROUTELOC0 |= (loc << _USART_ROUTELOC0_CSLOC_SHIFT);
			break;

#else /* CONFIG_SOC_GECKO_SERIES1 */
		case GECKO_FUN_SPI_SCK:
			pin_config.mode = gpioModePushPull;
			pin_config.out = 1;
			GPIO->USARTROUTE[usart_num].ROUTEEN |= GPIO_USART_ROUTEEN_CLKPEN;
			GPIO->USARTROUTE[usart_num].CLKROUTE =
				(pin_config.pin << _GPIO_USART_CLKROUTE_PIN_SHIFT) |
				(pin_config.port << _GPIO_USART_CLKROUTE_PORT_SHIFT);
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_SPI_MOSI:
			pin_config.mode = gpioModePushPull;
			pin_config.out = 1;
			GPIO->USARTROUTE[usart_num].ROUTEEN |= GPIO_USART_ROUTEEN_TXPEN;
			GPIO->USARTROUTE[usart_num].TXROUTE =
				(pin_config.pin << _GPIO_USART_TXROUTE_PIN_SHIFT) |
				(pin_config.port << _GPIO_USART_TXROUTE_PORT_SHIFT);
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;

		case GECKO_FUN_SPI_MISO:
			pin_config.mode = gpioModeInput;
			pin_config.out = 1;
			GPIO->USARTROUTE[usart_num].ROUTEEN |= GPIO_USART_ROUTEEN_RXPEN;
			GPIO->USARTROUTE[usart_num].RXROUTE =
				(pin_config.pin << _GPIO_USART_RXROUTE_PIN_SHIFT) |
				(pin_config.port << _GPIO_USART_RXROUTE_PORT_SHIFT);
			GPIO_PinModeSet(pin_config.port, pin_config.pin, pin_config.mode,
					pin_config.out);
			break;
#endif /* CONFIG_SOC_GECKO_SERIES1 */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#endif /* CONFIG_SPI_GECKO */

		default:
			return -ENOTSUP;
		}
<<<<<<< HEAD
#ifdef CONFIG_SPI_GECKO
		GPIO_PinModeSet(spi_pin_cfg.port, spi_pin_cfg.pin,
				spi_pin_cfg.mode, spi_pin_cfg.out);
#endif /* CONFIG_SPI_GECKO */
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	return 0;
}
