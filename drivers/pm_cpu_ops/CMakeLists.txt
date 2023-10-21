# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_PM_CPU_OPS pm_cpu_ops_weak_impl.c)

zephyr_library_sources_ifdef(CONFIG_PM_CPU_OPS_PSCI pm_cpu_ops_psci.c)
<<<<<<< HEAD
=======

zephyr_library_sources_ifdef(CONFIG_PSCI_SHELL psci_shell.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
