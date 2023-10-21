# Copyright (c) 2022 Renesas Electronics Corporation
#
# SPDX-License-Identifier: Apache-2.0

'''Runner for flashing with ezFlashCLI.'''
from runners.core import ZephyrBinaryRunner, RunnerCaps

DEFAULT_EZFLASHCLI = "ezFlashCLI"

class EzFlashCliBinaryRunner(ZephyrBinaryRunner):
    '''Runner front-end for ezFlashCLI'''

<<<<<<< HEAD
    def __init__(self, cfg, tool, sn, erase=False):
=======
    def __init__(self, cfg, tool, sn, erase=False, reset=True):
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
        super().__init__(cfg)
        self.bin_ = cfg.bin_file

        self.tool = tool
        self.sn_arg = ['-j', f'{sn}'] if sn is not None else []
        self.erase = bool(erase)
<<<<<<< HEAD
=======
        self.reset = bool(reset)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

    @classmethod
    def name(cls):
        return 'ezflashcli'

    @classmethod
    def capabilities(cls):
<<<<<<< HEAD
        return RunnerCaps(commands={'flash'}, erase=True)
=======
        return RunnerCaps(commands={'flash'}, erase=True, reset=True)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

    @classmethod
    def do_add_parser(cls, parser):
        parser.add_argument('--tool', default=DEFAULT_EZFLASHCLI,
                            help='ezFlashCLI path, default is '
                                f'{DEFAULT_EZFLASHCLI}')
        parser.add_argument('--sn', default=None, required=False,
                            help='J-Link probe serial number')

<<<<<<< HEAD
=======
        parser.set_defaults(reset=True)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    @classmethod
    def do_create(cls, cfg, args):
        return EzFlashCliBinaryRunner(cfg, tool=args.tool, sn=args.sn,
                                      erase=args.erase)

    def needs_product_header(self):
        # Applications linked to code partition are meant to be run by MCUboot
        # and do not require product header. Other applications and MCUboot itself
        # are run by internal bootloader and thus require valid product header.

        is_mcuboot = self.build_conf.getboolean('CONFIG_MCUBOOT')
        uses_code_partition = self.build_conf.getboolean('CONFIG_USE_DT_CODE_PARTITION')

        return is_mcuboot or not uses_code_partition

    def program_bin(self):

        if self.erase:
            self.logger.info("Erasing flash...")
            self.check_call([self.tool] + self.sn_arg + ["erase_flash"])

        self.logger.info(f"Flashing {self.bin_}...")
        if self.needs_product_header():
            # Write product header and application image at fixed offset as required
            # by internal bootloader.
            self.check_call([self.tool] + self.sn_arg + ["image_flash", self.bin_])
        else:
            load_offset = self.build_conf['CONFIG_FLASH_LOAD_OFFSET']
            self.check_call([self.tool] + self.sn_arg + ["write_flash", f'0x{load_offset:x}', self.bin_])

<<<<<<< HEAD
    def reset(self):
=======
    def reset_device(self):
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
        self.logger.info("Resetting...")
        self.check_call([self.tool] + self.sn_arg + ["go"])

    def do_run(self, command, **kwargs):
        self.require(self.tool)
        self.ensure_output('bin')
        self.program_bin()
<<<<<<< HEAD
        self.reset()
=======
        if self.reset:
            self.reset_device()
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
