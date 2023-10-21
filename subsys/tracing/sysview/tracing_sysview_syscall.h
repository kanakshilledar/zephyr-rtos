/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_TRACING_SYSVIEW_SYSCALL_H_
#define ZEPHYR_TRACING_SYSVIEW_SYSCALL_H_

#include <SEGGER_SYSVIEW.h>
#include <tracing_sysview_ids.h>

<<<<<<< HEAD
#define sys_port_trace_syscall_enter(id, name, ...)		\
	SEGGER_SYSVIEW_RecordU32(TID_SYSCALL, (uint32_t)id)

#define sys_port_trace_syscall_exit(id, name, ...) \
	SEGGER_SYSVIEW_RecordEndCallU32(TID_SYSCALL, (uint32_t)id)
=======
#define sys_port_trace_syscall_enter(id, name, ...)	\
	SEGGER_SYSVIEW_RecordString(TID_SYSCALL, (const char *)#name)

#define sys_port_trace_syscall_exit(id, name, ...)	\
	SEGGER_SYSVIEW_RecordEndCall(TID_SYSCALL)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#endif /* ZEPHYR_TRACING_SYSVIEW_SYSCALL_H_ */
