.. _ivshmem_driver:

Inter-VM Shared Memory
######################

.. contents::
   :local:
   :depth: 2

Overview
********

As Zephyr is enabled to run as a guest OS on Qemu and
`ACRN <https://projectacrn.github.io/latest/tutorials/using_zephyr_as_uos.html>`_
it might be necessary to make VMs aware of each other, or aware of the host.
This is made possible by exposing a shared memory among parties via a feature
called ivshmem, which stands for inter-VM Shared Memory.

<<<<<<< HEAD
The Two types are supported: a plain shared memory (ivshmem-plain) or a shared
=======
The two types are supported: a plain shared memory (ivshmem-plain) or a shared
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
memory with the ability for a VM to generate an interruption on another, and
thus to be interrupted as well itself (ivshmem-doorbell).

Please refer to the official `Qemu ivshmem documentation
<https://www.qemu.org/docs/master/system/devices/ivshmem.html>`_ for more information.

Support
*******

<<<<<<< HEAD
Zephyr supports both version: plain and doorbell. Ivshmem driver can be build
=======
Zephyr supports both versions: plain and doorbell. Ivshmem driver can be built
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
by enabling :kconfig:option:`CONFIG_IVSHMEM`. By default, this will expose the plain
version. :kconfig:option:`CONFIG_IVSHMEM_DOORBELL` needs to be enabled to get the
doorbell version.

Because the doorbell version uses MSI-X vectors to support notification vectors,
<<<<<<< HEAD
the :kconfig:option:`CONFIG_IVSHMEM_MSI_X_VECTORS` has to be tweaked to the amount of
=======
the :kconfig:option:`CONFIG_IVSHMEM_MSI_X_VECTORS` has to be tweaked to the number of
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
vectors that will be needed.

Note that a tiny shell module can be exposed to test the ivshmem feature by
enabling :kconfig:option:`CONFIG_IVSHMEM_SHELL`.

ivshmem-v2
**********

Zephyr also supports ivshmem-v2:

https://github.com/siemens/jailhouse/blob/master/Documentation/ivshmem-v2-specification.md

This is primarily used for IPC in the Jailhouse hypervisor
<<<<<<< HEAD
(e.g. :ref:`eth_ivshmem_sample`). It is also possible to use ivshmem-v2 without
=======
(e.g. :zephyr:code-sample:`eth-ivshmem`). It is also possible to use ivshmem-v2 without
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
Jailhouse by building the Siemens fork of QEMU, and modifying the QEMU launch flags:

https://github.com/siemens/qemu/tree/wip/ivshmem2

API Reference
*************

.. doxygengroup:: ivshmem
