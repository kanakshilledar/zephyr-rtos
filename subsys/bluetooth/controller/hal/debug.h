/*
 * Copyright (c) 2016 Nordic Semiconductor ASA
 * Copyright (c) 2016 Vinayak Kariappa Chettimada
 *
 * SPDX-License-Identifier: Apache-2.0
 */

<<<<<<< HEAD
 #include "common/assert.h"
=======
#include "common/assert.h"
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#ifdef CONFIG_BT_CTLR_ASSERT_HANDLER
void bt_ctlr_assert_handle(char *file, uint32_t line);
#define LL_ASSERT(cond) \
		if (!(cond)) { \
			BT_ASSERT_PRINT(cond); \
			bt_ctlr_assert_handle(__FILE__, __LINE__); \
		}
#define LL_ASSERT_MSG(cond, fmt, ...) \
		if (!(cond)) { \
			BT_ASSERT_PRINT(cond); \
			BT_ASSERT_PRINT_MSG(fmt, ##__VA_ARGS__); \
			bt_ctlr_assert_handle(__FILE__, __LINE__); \
		}
#else
#define LL_ASSERT(cond) \
		BT_ASSERT(cond)
#define LL_ASSERT_MSG(cond, fmt, ...) \
		BT_ASSERT_MSG(cond, fmt, ##__VA_ARGS__)
#endif

<<<<<<< HEAD
=======
#if defined(CONFIG_BT_CTLR_ASSERT_OVERHEAD_START)
#define LL_ASSERT_OVERHEAD(overhead) \
	LL_ASSERT_MSG(false, "%s: Actual EVENT_OVERHEAD_START_US = %u", \
		      __func__, HAL_TICKER_TICKS_TO_US(overhead));
#else /* !CONFIG_BT_CTLR_ASSERT_OVERHEAD_START */
#define LL_ASSERT_OVERHEAD(overhead) ARG_UNUSED(overhead)
#endif /* !CONFIG_BT_CTLR_ASSERT_OVERHEAD_START */

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include "hal/debug_vendor_hal.h"
