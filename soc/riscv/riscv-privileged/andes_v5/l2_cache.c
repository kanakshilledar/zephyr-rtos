/*
 * Copyright (c) 2021 Andes Technology Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT andestech_l2c

/**
 * @brief Andes V5 L2 Cache Controller driver
 */

#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/arch/cpu.h>
#include <zephyr/drivers/syscon.h>
#include <zephyr/logging/log.h>
<<<<<<< HEAD
LOG_MODULE_REGISTER(andes_v5_l2_cache, CONFIG_SOC_LOG_LEVEL);

#if DT_NODE_EXISTS(DT_INST(0, andestech_l2c))

/* SMU Configuration Register offset */
#define SMU_SYSTEMCFG		0x08

/* Register bitmask */
#define SMU_SYSTEMCFG_L2C	BIT(8)

/*
 * L2C Register Base Address
 */

#define ANDES_V5_L2C_BASE	DT_INST_REG_ADDR(0)

/*
 * L2C Register Offset
 */

#define L2C_CONFIG		0x00
#define L2C_CTRL		0x08

/*
 * L2C Helper Constant
 */

/* L2 cache version */
#define L2C_CONFIG_VERSION_SHIFT        24

/* enable L2C */
#define L2C_CTRL_CEN		BIT(0)

/* instruction prefetch depth */
=======
#include <zephyr/arch/riscv/csr.h>

LOG_MODULE_REGISTER(andes_v5_l2_cache, CONFIG_SOC_LOG_LEVEL);

/* L2C Register Base Address */
#define ANDES_V5_L2C_BASE	DT_INST_REG_ADDR(0)

/* L2C Register Offset */
#define L2C_CONFIG		(ANDES_V5_L2C_BASE + 0x00)
#define L2C_CTRL		(ANDES_V5_L2C_BASE + 0x08)

/* L2C Helper Constant */
#define L2C_CONFIG_VER		GENMASK64(31, 24)
#define L2C_CTRL_CEN		BIT(0)

/* Instruction prefetch depth */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#define IPFDPT_FIELD(x)		(x << 3)
#define L2C_CTRL_IPFDPT_0	IPFDPT_FIELD(0)
#define L2C_CTRL_IPFDPT_1	IPFDPT_FIELD(1)
#define L2C_CTRL_IPFDPT_2	IPFDPT_FIELD(2)
#define L2C_CTRL_IPFDPT_3	IPFDPT_FIELD(3)

<<<<<<< HEAD
/* data prefetch depth */
=======
/* Data prefetch depth */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#define DPFDPT_FIELD(x)		(x << 5)
#define L2C_CTRL_DPFDPT_0	DPFDPT_FIELD(0)
#define L2C_CTRL_DPFDPT_2	DPFDPT_FIELD(1)
#define L2C_CTRL_DPFDPT_4	DPFDPT_FIELD(2)
#define L2C_CTRL_DPFDPT_8	DPFDPT_FIELD(3)

<<<<<<< HEAD
static void andes_v5_l2c_enable(void)
{
	unsigned long mcache_ctl;
	volatile uint64_t *l2c_ctrl =
		INT_TO_POINTER(ANDES_V5_L2C_BASE + L2C_CTRL);

	__asm__ volatile ("csrr %0, %1"
		: "=r" (mcache_ctl) : "i" (NDS_MCACHE_CTL));

	/* Enable L2 cache if L1 I/D cache enabled */
	if (mcache_ctl & (BIT(1) | BIT(0))) {
		volatile uint64_t *l2c_config =
			INT_TO_POINTER(ANDES_V5_L2C_BASE + L2C_CONFIG);

		*l2c_ctrl |= (L2C_CTRL_IPFDPT_3 | L2C_CTRL_DPFDPT_8);

		/* Enable L2 cache manually if device version less than 0xF0 */
		if (!((*l2c_config >> L2C_CONFIG_VERSION_SHIFT) & 0xF0)) {
			*l2c_ctrl |= L2C_CTRL_CEN;
		}
	} else {
		/* Disable L2 cache */
		*l2c_ctrl &= ~L2C_CTRL_CEN;
=======
#if DT_HAS_COMPAT_STATUS_OKAY(andestech_atcsmu100)
/* SMU Register offset */
#define SMU_SYSTEMCFG		0x08

/* SMU Helper Constant */
#define SMU_SYSTEMCFG_L2C	BIT(8)
#endif

static void andes_v5_l2c_enable(void)
{
	uint32_t l2c_ctrl = sys_read32(L2C_CTRL);

	/* Enable L2C if I-cache or D-cache is enabled */
	if (csr_read(NDS_MCACHE_CTL) & BIT_MASK(2)) {
		uint32_t l2c_config = sys_read32(L2C_CONFIG);

		/* Memory barrier, flush all I/D-Cache before setting L2C */
		__asm__ volatile ("fence.i");

		l2c_ctrl |= (L2C_CTRL_IPFDPT_3 | L2C_CTRL_DPFDPT_8);
		sys_write32(l2c_ctrl, L2C_CTRL);

		/* Enable L2C for Gen1 L2C, Gen2 L2C defaults to enable */
		if ((l2c_config & L2C_CONFIG_VER) < (16 << 24)) {
			l2c_ctrl = sys_read32(L2C_CTRL);
			l2c_ctrl |= L2C_CTRL_CEN;
			sys_write32(l2c_ctrl, L2C_CTRL);
		}
	} else {
		/* Disable L2C */
		l2c_ctrl &= ~L2C_CTRL_CEN;
		sys_write32(l2c_ctrl, L2C_CTRL);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}
}

static int andes_v5_l2c_init(void)
{
<<<<<<< HEAD
#if DT_NODE_HAS_STATUS(DT_INST(0, syscon), okay)
	uint32_t system_cfg;
	const struct device *const syscon_dev = DEVICE_DT_GET(DT_NODELABEL(syscon));


	if (device_is_ready(syscon_dev)) {
		syscon_read_reg(syscon_dev, SMU_SYSTEMCFG, &system_cfg);

		if (!(system_cfg & SMU_SYSTEMCFG_L2C)) {
			/* This SoC doesn't have L2 cache */
			return -ENODEV;
		}
	} else {
		LOG_DBG("Init might fail for some hardware combinations "
					"if syscon driver isn't ready\n");
=======
#if DT_NODE_HAS_COMPAT_STATUS(DT_NODELABEL(syscon), andestech_atcsmu100, okay)
	const struct device *const syscon_dev = DEVICE_DT_GET(DT_NODELABEL(syscon));

	if (device_is_ready(syscon_dev)) {
		uint32_t system_cfg;

		syscon_read_reg(syscon_dev, SMU_SYSTEMCFG, &system_cfg);

		/* Platform doesn't have L2C */
		if (!(system_cfg & SMU_SYSTEMCFG_L2C)) {
			return -ENODEV;
		}
	} else {
		LOG_ERR("Syscon driver should be initialized before L2 Cache "
			"initialization.");
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}
#endif

	andes_v5_l2c_enable();
<<<<<<< HEAD
=======

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	return 0;
}

SYS_INIT(andes_v5_l2c_init, PRE_KERNEL_2, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
<<<<<<< HEAD

#endif /* DT_NODE_EXISTS(DT_INST(0, andestech_l2c)) */
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
