# Copyright (c) 2023 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: Apache-2.0

from __future__ import annotations

import logging
from dataclasses import dataclass, field
from pathlib import Path

import pytest

logger = logging.getLogger(__name__)


@dataclass
class DeviceConfig:
<<<<<<< HEAD
    platform: str = ''
    type: str = ''
=======
    type: str
    build_dir: Path
    base_timeout: float = 60.0  # [s]
    platform: str = ''
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    serial: str = ''
    baud: int = 115200
    runner: str = ''
    id: str = ''
    product: str = ''
    serial_pty: str = ''
    west_flash_extra_args: list[str] = field(default_factory=list, repr=False)
<<<<<<< HEAD
    flashing_timeout: int = 60  # [s]
    build_dir: Path | str = ''
    binary_file: Path | str = ''
    name: str = ''
    pre_script: str = ''
    post_script: str = ''
    post_flash_script: str = ''
=======
    name: str = ''
    pre_script: Path | None = None
    post_script: Path | None = None
    post_flash_script: Path | None = None
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d


@dataclass
class TwisterHarnessConfig:
    """Store Twister harness configuration to have easy access in test."""
<<<<<<< HEAD
    output_dir: Path = Path('twister_harness_out')
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    devices: list[DeviceConfig] = field(default_factory=list, repr=False)

    @classmethod
    def create(cls, config: pytest.Config) -> TwisterHarnessConfig:
        """Create new instance from pytest.Config."""
<<<<<<< HEAD
        output_dir: Path = config.option.output_dir
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

        devices = []

        west_flash_extra_args: list[str] = []
        if config.option.west_flash_extra_args:
            west_flash_extra_args = [w.strip() for w in config.option.west_flash_extra_args.split(',')]
        device_from_cli = DeviceConfig(
<<<<<<< HEAD
            platform=config.option.platform,
            type=config.option.device_type,
=======
            type=config.option.device_type,
            build_dir=_cast_to_path(config.option.build_dir),
            base_timeout=config.option.base_timeout,
            platform=config.option.platform,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
            serial=config.option.device_serial,
            baud=config.option.device_serial_baud,
            runner=config.option.runner,
            id=config.option.device_id,
            product=config.option.device_product,
            serial_pty=config.option.device_serial_pty,
            west_flash_extra_args=west_flash_extra_args,
<<<<<<< HEAD
            flashing_timeout=config.option.flashing_timeout,
            build_dir=config.option.build_dir,
            binary_file=config.option.binary_file,
            pre_script=config.option.pre_script,
            post_script=config.option.post_script,
            post_flash_script=config.option.post_flash_script,
=======
            pre_script=_cast_to_path(config.option.pre_script),
            post_script=_cast_to_path(config.option.post_script),
            post_flash_script=_cast_to_path(config.option.post_flash_script),
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
        )

        devices.append(device_from_cli)

        return cls(
<<<<<<< HEAD
            output_dir=output_dir,
            devices=devices
        )
=======
            devices=devices
        )


def _cast_to_path(path: str | None) -> Path | None:
    if path is None:
        return None
    return Path(path)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
