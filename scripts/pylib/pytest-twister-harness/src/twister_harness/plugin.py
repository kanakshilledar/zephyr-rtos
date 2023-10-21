# Copyright (c) 2023 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: Apache-2.0

from __future__ import annotations

import logging
import os
<<<<<<< HEAD
from pathlib import Path

import pytest

from twister_harness.log import configure_logging
=======

import pytest

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
from twister_harness.twister_harness_config import TwisterHarnessConfig

logger = logging.getLogger(__name__)

pytest_plugins = (
<<<<<<< HEAD
    'twister_harness.fixtures.dut'
=======
    'twister_harness.fixtures'
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
)


def pytest_addoption(parser: pytest.Parser):
    twister_harness_group = parser.getgroup('Twister harness')
    twister_harness_group.addoption(
        '--twister-harness',
        action='store_true',
        default=False,
<<<<<<< HEAD
        help='Activate Twister harness plugin'
=======
        help='Activate Twister harness plugin.'
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    )
    parser.addini(
        'twister_harness',
        'Activate Twister harness plugin',
        type='bool'
    )
    twister_harness_group.addoption(
<<<<<<< HEAD
        '-O',
        '--outdir',
        metavar='PATH',
        dest='output_dir',
        help='Output directory for logs. If not provided then use '
             '--build-dir path as default.'
    )
    twister_harness_group.addoption(
        '--platform',
        help='Choose specific platform'
=======
        '--base-timeout',
        type=float,
        default=60.0,
        help='Set base timeout (in seconds) used during monitoring if some '
             'operations are finished in a finite amount of time (e.g. waiting '
             'for flashing).'
    )
    twister_harness_group.addoption(
        '--build-dir',
        metavar='PATH',
        help='Directory with built application.'
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    )
    twister_harness_group.addoption(
        '--device-type',
        choices=('native', 'qemu', 'hardware', 'unit', 'custom'),
<<<<<<< HEAD
        help='Choose type of device (hardware, qemu, etc.)'
    )
    twister_harness_group.addoption(
        '--device-serial',
        help='Serial device for accessing the board '
             '(e.g., /dev/ttyACM0)'
=======
        help='Choose type of device (hardware, qemu, etc.).'
    )
    twister_harness_group.addoption(
        '--platform',
        help='Name of used platform (qemu_x86, nrf52840dk_nrf52840, etc.).'
    )
    twister_harness_group.addoption(
        '--device-serial',
        help='Serial device for accessing the board (e.g., /dev/ttyACM0).'
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    )
    twister_harness_group.addoption(
        '--device-serial-baud',
        type=int,
        default=115200,
<<<<<<< HEAD
        help='Serial device baud rate (default 115200)'
    )
    twister_harness_group.addoption(
        '--runner',
        help='use the specified west runner (pyocd, nrfjprog, etc)'
    )
    twister_harness_group.addoption(
        '--device-id',
        help='ID of connected hardware device (for example 000682459367)'
    )
    twister_harness_group.addoption(
        '--device-product',
        help='Product name of connected hardware device (for example "STM32 STLink")'
    )
    twister_harness_group.addoption(
        '--device-serial-pty',
        metavar='PATH',
        help='Script for controlling pseudoterminal. '
             'E.g --device-testing --device-serial-pty=<script>'
=======
        help='Serial device baud rate (default 115200).'
    )
    twister_harness_group.addoption(
        '--runner',
        help='Use the specified west runner (pyocd, nrfjprog, etc.).'
    )
    twister_harness_group.addoption(
        '--device-id',
        help='ID of connected hardware device (for example 000682459367).'
    )
    twister_harness_group.addoption(
        '--device-product',
        help='Product name of connected hardware device (e.g. "STM32 STLink").'
    )
    twister_harness_group.addoption(
        '--device-serial-pty',
        help='Script for controlling pseudoterminal.'
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    )
    twister_harness_group.addoption(
        '--west-flash-extra-args',
        help='Extend parameters for west flash. '
             'E.g. --west-flash-extra-args="--board-id=foobar,--erase" '
<<<<<<< HEAD
             'will translate to "west flash -- --board-id=foobar --erase"'
    )
    twister_harness_group.addoption(
        '--flashing-timeout',
        type=int,
        default=60,
        help='Set timeout for the device flash operation in seconds.'
    )
    twister_harness_group.addoption(
        '--build-dir',
        dest='build_dir',
        metavar='PATH',
        help='Directory with built application.'
    )
    twister_harness_group.addoption(
        '--binary-file',
        metavar='PATH',
        help='Path to file which should be flashed.'
    )
    twister_harness_group.addoption(
        '--pre-script',
        metavar='PATH'
    )
    twister_harness_group.addoption(
        '--post-script',
        metavar='PATH'
    )
    twister_harness_group.addoption(
        '--post-flash-script',
        metavar='PATH'
=======
             'will translate to "west flash -- --board-id=foobar --erase".'
    )
    twister_harness_group.addoption(
        '--pre-script',
        metavar='PATH',
        help='Script executed before flashing and connecting to serial.'
    )
    twister_harness_group.addoption(
        '--post-flash-script',
        metavar='PATH',
        help='Script executed after flashing.'
    )
    twister_harness_group.addoption(
        '--post-script',
        metavar='PATH',
        help='Script executed after closing serial connection.'
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    )


def pytest_configure(config: pytest.Config):
    if config.getoption('help'):
        return

    if not (config.getoption('twister_harness') or config.getini('twister_harness')):
        return

<<<<<<< HEAD
    validate_options(config)

    if config.option.output_dir is None:
        config.option.output_dir = config.option.build_dir
    config.option.output_dir = _normalize_path(config.option.output_dir)

    # create output directory if not exists
    os.makedirs(config.option.output_dir, exist_ok=True)

    configure_logging(config)
=======
    _normalize_paths(config)
    _validate_options(config)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

    config.twister_harness_config = TwisterHarnessConfig.create(config)  # type: ignore


<<<<<<< HEAD
def validate_options(config: pytest.Config) -> None:
    """Verify if user provided proper options"""
    # TBD


def _normalize_path(path: str | Path) -> str:
    path = os.path.expanduser(os.path.expandvars(path))
    path = os.path.normpath(os.path.abspath(path))
=======
def _validate_options(config: pytest.Config) -> None:
    if not config.option.build_dir:
        raise Exception('--build-dir has to be provided')
    if not os.path.isdir(config.option.build_dir):
        raise Exception(f'Provided --build-dir does not exist: {config.option.build_dir}')
    if not config.option.device_type:
        raise Exception('--device-type has to be provided')


def _normalize_paths(config: pytest.Config) -> None:
    """Normalize paths provided by user via CLI"""
    config.option.build_dir = _normalize_path(config.option.build_dir)
    config.option.pre_script = _normalize_path(config.option.pre_script)
    config.option.post_script = _normalize_path(config.option.post_script)
    config.option.post_flash_script = _normalize_path(config.option.post_flash_script)


def _normalize_path(path: str | None) -> str:
    if path is not None:
        path = os.path.expanduser(os.path.expandvars(path))
        path = os.path.normpath(os.path.abspath(path))
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    return path
