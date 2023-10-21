/*
 * Copyright (c) 2021 EPAM Systems
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef __XEN_HVM_H__
#define __XEN_HVM_H__

#include <zephyr/xen/public/hvm/hvm_op.h>
#include <zephyr/xen/public/hvm/params.h>

#include <zephyr/kernel.h>

<<<<<<< HEAD
int hvm_set_parameter(int idx, uint64_t value);
int hvm_get_parameter(int idx, uint64_t *value);
=======
int hvm_set_parameter(int idx, int domid, uint64_t value);
int hvm_get_parameter(int idx, int domid, uint64_t *value);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#endif /* __XEN_HVM_H__ */
