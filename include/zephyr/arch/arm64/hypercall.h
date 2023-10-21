<<<<<<< HEAD
/*
 * Copyright (c) 2021-2022 EPAM Systems
 *
 * SPDX-License-Identifier: Apache-2.0
=======
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2021-2023 EPAM Systems
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 */

#ifndef ZEPHYR_INCLUDE_ARCH_ARM64_HYPERCALL_H_
#define ZEPHYR_INCLUDE_ARCH_ARM64_HYPERCALL_H_

/* defined in hypercall.S by HYPERCALL(hypercall) */
int HYPERVISOR_console_io(int op, int cnt, char *str);
int HYPERVISOR_sched_op(int op, void *param);
int HYPERVISOR_event_channel_op(int op, void *param);
int HYPERVISOR_hvm_op(int op, void *param);
int HYPERVISOR_memory_op(int op, void *param);
int HYPERVISOR_grant_table_op(int op, void *uop, unsigned int count);

<<<<<<< HEAD
=======
#ifdef CONFIG_XEN_DOM0
int HYPERVISOR_domctl(void *param);
#endif

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#endif /* ZEPHYR_INCLUDE_ARCH_ARM64_HYPERCALL_H_ */
