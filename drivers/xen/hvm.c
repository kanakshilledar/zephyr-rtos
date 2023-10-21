/*
 * Copyright (c) 2021 EPAM Systems
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/arch/arm64/hypercall.h>
#include <zephyr/xen/hvm.h>
#include <zephyr/xen/public/hvm/hvm_op.h>
#include <zephyr/xen/public/hvm/params.h>

#include <zephyr/kernel.h>

<<<<<<< HEAD
int hvm_set_parameter(int idx, uint64_t value)
{
	struct xen_hvm_param xhv;

	xhv.domid = DOMID_SELF;
=======
int hvm_set_parameter(int idx, int domid, uint64_t value)
{
	struct xen_hvm_param xhv;

	xhv.domid = domid;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	xhv.index = idx;
	xhv.value = value;

	return HYPERVISOR_hvm_op(HVMOP_set_param, &xhv);
}

<<<<<<< HEAD
int hvm_get_parameter(int idx, uint64_t *value)
=======
int hvm_get_parameter(int idx, int domid, uint64_t *value)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	int ret = 0;
	struct xen_hvm_param xhv;

<<<<<<< HEAD
	xhv.domid = DOMID_SELF;
=======
	xhv.domid = domid;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	xhv.index = idx;

	ret = HYPERVISOR_hvm_op(HVMOP_get_param, &xhv);
	if (ret < 0) {
		return ret;
	}

	*value = xhv.value;
	return ret;
}
