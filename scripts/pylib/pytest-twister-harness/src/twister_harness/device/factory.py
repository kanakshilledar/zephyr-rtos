# Copyright (c) 2023 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: Apache-2.0

from __future__ import annotations

import logging
from typing import Type

<<<<<<< HEAD
from twister_harness.device.device_abstract import DeviceAbstract
from twister_harness.device.hardware_adapter import HardwareAdapter
from twister_harness.device.qemu_adapter import QemuAdapter
from twister_harness.device.simulator_adapter import (
=======
from twister_harness.device.device_adapter import DeviceAdapter
from twister_harness.device.hardware_adapter import HardwareAdapter
from twister_harness.device.qemu_adapter import QemuAdapter
from twister_harness.device.binary_adapter import (
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    CustomSimulatorAdapter,
    NativeSimulatorAdapter,
    UnitSimulatorAdapter,
)
from twister_harness.exceptions import TwisterHarnessException

logger = logging.getLogger(__name__)


class DeviceFactory:
<<<<<<< HEAD
    _devices: dict[str, Type[DeviceAbstract]] = {}
=======
    _devices: dict[str, Type[DeviceAdapter]] = {}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

    @classmethod
    def discover(cls):
        """Return available devices."""

    @classmethod
<<<<<<< HEAD
    def register_device_class(cls, name: str, klass: Type[DeviceAbstract]):
=======
    def register_device_class(cls, name: str, klass: Type[DeviceAdapter]):
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
        if name not in cls._devices:
            cls._devices[name] = klass

    @classmethod
<<<<<<< HEAD
    def get_device(cls, name: str) -> Type[DeviceAbstract]:
        logger.debug('Get device type "%s"', name)
        try:
            return cls._devices[name]
        except KeyError as e:
            logger.error('There is no device with name "%s"', name)
            raise TwisterHarnessException(f'There is no device with name "{name}"') from e
=======
    def get_device(cls, name: str) -> Type[DeviceAdapter]:
        logger.debug('Get device type "%s"', name)
        try:
            return cls._devices[name]
        except KeyError as exc:
            logger.error('There is no device with name "%s"', name)
            raise TwisterHarnessException(f'There is no device with name "{name}"') from exc
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d


DeviceFactory.register_device_class('custom', CustomSimulatorAdapter)
DeviceFactory.register_device_class('native', NativeSimulatorAdapter)
DeviceFactory.register_device_class('unit', UnitSimulatorAdapter)
DeviceFactory.register_device_class('hardware', HardwareAdapter)
DeviceFactory.register_device_class('qemu', QemuAdapter)
