/* Copyright (c) 2022 Google LLC
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file zephyr/dsp/dsp.h
 *
 * @brief Public APIs for Digital Signal Processing (DSP) math.
 */

#ifndef INCLUDE_ZEPHYR_DSP_DSP_H_
#define INCLUDE_ZEPHYR_DSP_DSP_H_

#ifdef CONFIG_DSP_BACKEND_HAS_STATIC
#define DSP_FUNC_SCOPE static
#else
#define DSP_FUNC_SCOPE
#endif

#ifdef CONFIG_DSP_BACKEND_HAS_AGU
#define DSP_DATA __agu
#else
#define DSP_DATA
#endif

#ifdef CONFIG_DSP_BACKEND_HAS_XDATA_SECTION
#define DSP_STATIC_DATA DSP_DATA __attribute__((section(".Xdata")))
#else
#define DSP_STATIC_DATA DSP_DATA
#endif

/**
 * @brief DSP Interface
 * @defgroup math_dsp DSP Interface
 */

#include <zephyr/dsp/types.h>

#include <zephyr/dsp/basicmath.h>

<<<<<<< HEAD
=======
#include <zephyr/dsp/print_format.h>

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include "zdsp_backend.h"

#endif /* INCLUDE_ZEPHYR_DSP_DSP_H_ */
