# Copyright (c) 2023 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: Apache-2.0

from __future__ import annotations

import logging
import os
import pty
import re
<<<<<<< HEAD
import shutil
import subprocess
from datetime import datetime
from typing import Generator

import serial

from twister_harness.device.device_abstract import DeviceAbstract
from twister_harness.exceptions import TwisterHarnessException
from twister_harness.helper import log_command
from twister_harness.log_files.log_file import DeviceLogFile, HandlerLogFile
=======
import subprocess
import time
from pathlib import Path

import serial
from twister_harness.device.device_adapter import DeviceAdapter
from twister_harness.exceptions import (
    TwisterHarnessException,
    TwisterHarnessTimeoutException,
)
from twister_harness.device.utils import log_command, terminate_process
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
from twister_harness.twister_harness_config import DeviceConfig

logger = logging.getLogger(__name__)


<<<<<<< HEAD
class HardwareAdapter(DeviceAbstract):
    """Adapter class for real device."""

    def __init__(self, device_config: DeviceConfig, **kwargs) -> None:
        super().__init__(device_config, **kwargs)
        self.connection: serial.Serial | None = None
        self.command: list[str] = []
        self.process_kwargs: dict = {
            'stdout': subprocess.PIPE,
            'stderr': subprocess.STDOUT,
            'env': self.env,
        }
        self.serial_pty_proc: subprocess.Popen | None = None

    def connect(self, timeout: float = 1) -> None:
        """
        Open serial connection.

        :param timeout: Read timeout value in seconds
        """
        if self.connection:
            # already opened
            return

        if self.device_config.pre_script:
            self.run_custom_script(self.device_config.pre_script, 30)

        serial_name = self._open_serial_pty() or self.device_config.serial
        logger.info('Opening serial connection for %s', serial_name)
        try:
            self.connection = serial.Serial(
                serial_name,
                baudrate=self.device_config.baud,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                bytesize=serial.EIGHTBITS,
                timeout=timeout
            )
        except serial.SerialException as e:
            logger.exception('Cannot open connection: %s', e)
            self._close_serial_pty()
            raise

        self.connection.flush()

    def disconnect(self) -> None:
        """Close serial connection."""
        if self.connection:
            serial_name = self.connection.port
            self.connection.close()
            self.connection = None
            logger.info('Closed serial connection for %s', serial_name)
        self._close_serial_pty()

    def stop(self) -> None:
        if self.device_config.post_script:
            self.run_custom_script(self.device_config.post_script, 30)

    def _open_serial_pty(self) -> str | None:
        """Open a pty pair, run process and return tty name"""
        if not self.device_config.serial_pty:
            return None
        master, slave = pty.openpty()
        try:
            self.serial_pty_proc = subprocess.Popen(
                re.split(',| ', self.device_config.serial_pty),
                stdout=master,
                stdin=master,
                stderr=master
            )
        except subprocess.CalledProcessError as e:
            logger.exception('Failed to run subprocess %s, error %s',
                             self.device_config.serial_pty, str(e))
            raise
        return os.ttyname(slave)

    def _close_serial_pty(self) -> None:
        """Terminate the process opened for serial pty script"""
        if self.serial_pty_proc:
            self.serial_pty_proc.terminate()
            self.serial_pty_proc.communicate()
            logger.info('Process %s terminated', self.device_config.serial_pty)
            self.serial_pty_proc = None

    def generate_command(self) -> None:
        """Return command to flash."""
        west = shutil.which('west')
        if west is None:
            raise TwisterHarnessException('west not found')

        command = [
            west,
=======
class HardwareAdapter(DeviceAdapter):
    """Adapter class for real device."""

    def __init__(self, device_config: DeviceConfig) -> None:
        super().__init__(device_config)
        self._flashing_timeout: float = self.base_timeout
        self._serial_connection: serial.Serial | None = None
        self._serial_pty_proc: subprocess.Popen | None = None
        self._serial_buffer: bytearray = bytearray()

        self.device_log_path: Path = device_config.build_dir / 'device.log'
        self._log_files.append(self.device_log_path)

    def generate_command(self) -> None:
        """Return command to flash."""
        command = [
            self.west,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
            'flash',
            '--skip-rebuild',
            '--build-dir', str(self.device_config.build_dir),
        ]

        command_extra_args = []
        if self.device_config.west_flash_extra_args:
            command_extra_args.extend(self.device_config.west_flash_extra_args)

<<<<<<< HEAD
        if runner := self.device_config.runner:
            command.extend(['--runner', runner])

            if board_id := self.device_config.id:
                if runner == 'pyocd':
                    command_extra_args.append('--board-id')
                    command_extra_args.append(board_id)
                elif runner == 'nrfjprog':
                    command_extra_args.append('--dev-id')
                    command_extra_args.append(board_id)
                elif runner == 'openocd' and self.device_config.product in ['STM32 STLink', 'STLINK-V3']:
                    command_extra_args.append('--cmd-pre-init')
                    command_extra_args.append(f'hla_serial {board_id}')
                elif runner == 'openocd' and self.device_config.product == 'EDBG CMSIS-DAP':
                    command_extra_args.append('--cmd-pre-init')
                    command_extra_args.append(f'cmsis_dap_serial {board_id}')
                elif runner == 'jlink':
                    command.append(f'--tool-opt=-SelectEmuBySN {board_id}')
                elif runner == 'stm32cubeprogrammer':
                    command.append(f'--tool-opt=sn={board_id}')
=======
        if self.device_config.runner:
            runner_base_args, runner_extra_args = self._prepare_runner_args()
            command.extend(runner_base_args)
            command_extra_args.extend(runner_extra_args)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

        if command_extra_args:
            command.append('--')
            command.extend(command_extra_args)
        self.command = command

<<<<<<< HEAD
    @staticmethod
    def run_custom_script(script, timeout):
        with subprocess.Popen(script, stderr=subprocess.PIPE, stdout=subprocess.PIPE) as proc:
            try:
                stdout, stderr = proc.communicate(timeout=timeout)
                logger.debug(stdout.decode())
                if proc.returncode != 0:
                    logger.error(f"Custom script failure: {stderr.decode(errors='ignore')}")

            except subprocess.TimeoutExpired:
                proc.kill()
                proc.communicate()
                logger.error("{} timed out".format(script))

    def flash_and_run(self, timeout: float = 60.0) -> None:
=======
    def _prepare_runner_args(self) -> tuple[list[str], list[str]]:
        base_args: list[str] = []
        extra_args: list[str] = []
        runner = self.device_config.runner
        base_args.extend(['--runner', runner])
        if board_id := self.device_config.id:
            if runner == 'pyocd':
                extra_args.append('--board-id')
                extra_args.append(board_id)
            elif runner == 'nrfjprog':
                extra_args.append('--dev-id')
                extra_args.append(board_id)
            elif runner == 'openocd' and self.device_config.product in ['STM32 STLink', 'STLINK-V3']:
                extra_args.append('--cmd-pre-init')
                extra_args.append(f'hla_serial {board_id}')
            elif runner == 'openocd' and self.device_config.product == 'EDBG CMSIS-DAP':
                extra_args.append('--cmd-pre-init')
                extra_args.append(f'cmsis_dap_serial {board_id}')
            elif runner == 'jlink':
                base_args.append(f'--tool-opt=-SelectEmuBySN {board_id}')
            elif runner == 'stm32cubeprogrammer':
                base_args.append(f'--tool-opt=sn={board_id}')
        return base_args, extra_args

    def _flash_and_run(self) -> None:
        """Flash application on a device."""
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
        if not self.command:
            msg = 'Flash command is empty, please verify if it was generated properly.'
            logger.error(msg)
            raise TwisterHarnessException(msg)
<<<<<<< HEAD
        if self.device_config.id:
            logger.info('Flashing device %s', self.device_config.id)
        log_command(logger, 'Flashing command', self.command, level=logging.INFO)
        try:
            process = subprocess.Popen(
                self.command,
                **self.process_kwargs
            )
        except subprocess.CalledProcessError:
            logger.error('Error while flashing device')
            raise TwisterHarnessException('Could not flash device')
        else:
            stdout = stderr = None
            try:
                stdout, stderr = process.communicate(timeout=self.device_config.flashing_timeout)
            except subprocess.TimeoutExpired:
                process.kill()
            finally:
                if stdout:
                    self.device_log_file.handle(data=stdout)
                    logger.debug(stdout.decode(errors='ignore'))
                if stderr:
                    self.device_log_file.handle(data=stderr)
            if process.returncode == 0:
                logger.info('Flashing finished')
            else:
                raise TwisterHarnessException(f'Could not flash device {self.device_config.id}')
        finally:
            if self.device_config.post_flash_script:
                self.run_custom_script(self.device_config.post_flash_script, 30)

    def iter_stdout_lines(self) -> Generator[str, None, None]:
        """Return output from serial."""
        if not self.connection:
            return
        self.connection.flush()
        self.connection.reset_input_buffer()
        while self.connection and self.connection.is_open:
            stream = self.connection.readline()
            self.handler_log_file.handle(data=stream)
            yield stream.decode(errors='ignore').strip()
        self.iter_object = None

    def write(self, data: bytes) -> None:
        """Write data to serial"""
        if self.connection:
            self.connection.write(data)

    def initialize_log_files(self) -> None:
        self.handler_log_file = HandlerLogFile.create(build_dir=self.device_config.build_dir)
        self.device_log_file = DeviceLogFile.create(build_dir=self.device_config.build_dir)
        start_msg = f'\n==== Logging started at {datetime.now()} ====\n'
        self.handler_log_file.handle(start_msg)
        self.device_log_file.handle(start_msg)
=======

        if self.device_config.pre_script:
            self._run_custom_script(self.device_config.pre_script, self.base_timeout)

        if self.device_config.id:
            logger.debug('Flashing device %s', self.device_config.id)
        log_command(logger, 'Flashing command', self.command, level=logging.DEBUG)

        process = stdout = None
        try:
            process = subprocess.Popen(self.command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, env=self.env)
            stdout, _ = process.communicate(timeout=self._flashing_timeout)
        except subprocess.TimeoutExpired as exc:
            process.kill()
            msg = f'Timeout occurred ({self._flashing_timeout}s) during flashing.'
            logger.error(msg)
            raise TwisterHarnessTimeoutException(msg) from exc
        except subprocess.SubprocessError as exc:
            msg = f'Flashing subprocess failed due to SubprocessError {exc}'
            logger.error(msg)
            raise TwisterHarnessTimeoutException(msg) from exc
        finally:
            if stdout is not None:
                stdout_decoded = stdout.decode(errors='ignore')
                with open(self.device_log_path, 'a+') as log_file:
                    log_file.write(stdout_decoded)
                logger.debug(f'Flashing output:\n{stdout_decoded}')
            if self.device_config.post_flash_script:
                self._run_custom_script(self.device_config.post_flash_script, self.base_timeout)
            if process is not None and process.returncode == 0:
                logger.debug('Flashing finished')
            else:
                msg = f'Could not flash device {self.device_config.id}'
                logger.error(msg)
                raise TwisterHarnessException(msg)

    def _connect_device(self) -> None:
        serial_name = self._open_serial_pty() or self.device_config.serial
        logger.debug('Opening serial connection for %s', serial_name)
        try:
            self._serial_connection = serial.Serial(
                serial_name,
                baudrate=self.device_config.baud,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                bytesize=serial.EIGHTBITS,
                timeout=self.base_timeout,
            )
        except serial.SerialException as exc:
            logger.exception('Cannot open connection: %s', exc)
            self._close_serial_pty()
            raise

        self._serial_connection.flush()
        self._serial_connection.reset_input_buffer()
        self._serial_connection.reset_output_buffer()

    def _open_serial_pty(self) -> str | None:
        """Open a pty pair, run process and return tty name"""
        if not self.device_config.serial_pty:
            return None
        master, slave = pty.openpty()
        try:
            self._serial_pty_proc = subprocess.Popen(
                re.split(',| ', self.device_config.serial_pty),
                stdout=master,
                stdin=master,
                stderr=master
            )
        except subprocess.CalledProcessError as exc:
            logger.exception('Failed to run subprocess %s, error %s', self.device_config.serial_pty, str(exc))
            raise
        return os.ttyname(slave)

    def _disconnect_device(self) -> None:
        if self._serial_connection:
            serial_name = self._serial_connection.port
            self._serial_connection.close()
            # self._serial_connection = None
            logger.debug('Closed serial connection for %s', serial_name)
        self._close_serial_pty()

    def _close_serial_pty(self) -> None:
        """Terminate the process opened for serial pty script"""
        if self._serial_pty_proc:
            self._serial_pty_proc.terminate()
            self._serial_pty_proc.communicate(timeout=self.base_timeout)
            logger.debug('Process %s terminated', self.device_config.serial_pty)
            self._serial_pty_proc = None

    def _close_device(self) -> None:
        if self.device_config.post_script:
            self._run_custom_script(self.device_config.post_script, self.base_timeout)

    def is_device_running(self) -> bool:
        return self._device_run.is_set()

    def is_device_connected(self) -> bool:
        return bool(
            self.is_device_running()
            and self._device_connected.is_set()
            and self._serial_connection
            and self._serial_connection.is_open
        )

    def _read_device_output(self) -> bytes:
        try:
            output = self._readline_serial()
        except (serial.SerialException, TypeError, IOError):
            # serial was probably disconnected
            output = b''
        return output

    def _readline_serial(self) -> bytes:
        """
        This method was created to avoid using PySerial built-in readline
        method which cause blocking reader thread even if there is no data to
        read. Instead for this, following implementation try to read data only
        if they are available. Inspiration for this code was taken from this
        comment:
        https://github.com/pyserial/pyserial/issues/216#issuecomment-369414522
        """
        line = self._readline_from_serial_buffer()
        if line is not None:
            return line
        while True:
            if self._serial_connection is None or not self._serial_connection.is_open:
                return b''
            elif self._serial_connection.in_waiting == 0:
                time.sleep(0.05)
                continue
            else:
                bytes_to_read = max(1, min(2048, self._serial_connection.in_waiting))
                output = self._serial_connection.read(bytes_to_read)
                self._serial_buffer.extend(output)
                line = self._readline_from_serial_buffer()
                if line is not None:
                    return line

    def _readline_from_serial_buffer(self) -> bytes | None:
        idx = self._serial_buffer.find(b"\n")
        if idx >= 0:
            line = self._serial_buffer[:idx+1]
            self._serial_buffer = self._serial_buffer[idx+1:]
            return bytes(line)
        else:
            return None

    def _write_to_device(self, data: bytes) -> None:
        self._serial_connection.write(data)

    def _flush_device_output(self) -> None:
        if self.is_device_connected():
            self._serial_connection.flush()
            self._serial_connection.reset_input_buffer()

    def _clear_internal_resources(self) -> None:
        super()._clear_internal_resources()
        self._serial_connection = None
        self._serial_pty_proc = None
        self._serial_buffer.clear()

    @staticmethod
    def _run_custom_script(script_path: str | Path, timeout: float) -> None:
        with subprocess.Popen(str(script_path), stderr=subprocess.PIPE, stdout=subprocess.PIPE) as proc:
            try:
                stdout, stderr = proc.communicate(timeout=timeout)
                logger.debug(stdout.decode())
                if proc.returncode != 0:
                    msg = f'Custom script failure: \n{stderr.decode(errors="ignore")}'
                    logger.error(msg)
                    raise TwisterHarnessException(msg)

            except subprocess.TimeoutExpired as exc:
                terminate_process(proc)
                proc.communicate(timeout=timeout)
                msg = f'Timeout occurred ({timeout}s) during execution custom script: {script_path}'
                logger.error(msg)
                raise TwisterHarnessTimeoutException(msg) from exc
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
