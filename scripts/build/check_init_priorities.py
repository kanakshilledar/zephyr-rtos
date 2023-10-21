#!/usr/bin/env python3

# Copyright 2023 Google LLC
# SPDX-License-Identifier: Apache-2.0

"""
Checks the initialization priorities

<<<<<<< HEAD
This script parses the object files in the specified build directory, creates a
list of known devices and their effective initialization priorities and
compares that with the device dependencies inferred from the devicetree
hierarchy.
=======
This script parses a Zephyr executable file, creates a list of known devices
and their effective initialization priorities and compares that with the device
dependencies inferred from the devicetree hierarchy.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

This can be used to detect devices that are initialized in the incorrect order,
but also devices that are initialized at the same priority but depends on each
other, which can potentially break if the linking order is changed.
<<<<<<< HEAD
=======

Optionally, it can also produce a human readable list of the initialization
calls for the various init levels.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
"""

import argparse
import logging
import os
import pathlib
import pickle
import sys

from elftools.elf.elffile import ELFFile
<<<<<<< HEAD
from elftools.elf.relocation import RelocationSection
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
from elftools.elf.sections import SymbolTableSection

# This is needed to load edt.pickle files.
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..",
                                "dts", "python-devicetree", "src"))
from devicetree import edtlib  # pylint: disable=unused-import

<<<<<<< HEAD
# Prefix used for relocation sections containing initialization data, as in
# sequence of "struct init_entry".
_INIT_SECTION_PREFIX = (".rel.z_init_", ".rela.z_init_")

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
# Prefix used for "struct device" reference initialized based on devicetree
# entries with a known ordinal.
_DEVICE_ORD_PREFIX = "__device_dts_ord_"

<<<<<<< HEAD
# File name suffix for object files to be scanned.
_OBJ_FILE_SUFFIX = ".c.obj"

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
# Defined init level in order of priority.
_DEVICE_INIT_LEVELS = ["EARLY", "PRE_KERNEL_1", "PRE_KERNEL_2", "POST_KERNEL",
                      "APPLICATION", "SMP"]

<<<<<<< HEAD
# File name to check for detecting and skiping nested build directories.
_BUILD_DIR_DETECT_FILE = "CMakeCache.txt"

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
# List of compatibles for node where the initialization priority should be the
# opposite of the device tree inferred dependency.
_INVERTED_PRIORITY_COMPATIBLES = frozenset()

<<<<<<< HEAD
class Priority:
    """Parses and holds a device initialization priority.

    Parses an ELF section name for the corresponding initialization level and
    priority, for example ".rel.z_init_PRE_KERNEL_155_" for "PRE_KERNEL_1 55".

=======
# List of compatibles for nodes where we don't check the priority.
_IGNORE_COMPATIBLES = frozenset([
        # There is no direct dependency between the CDC ACM UART and the USB
        # device controller, the logical connection is established after USB
        # device support is enabled.
        "zephyr,cdc-acm-uart",
        ])

class Priority:
    """Parses and holds a device initialization priority.

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    The object can be used for comparing levels with one another.

    Attributes:
        name: the section name
    """
<<<<<<< HEAD
    def __init__(self, name):
        for idx, level in enumerate(_DEVICE_INIT_LEVELS):
            if level in name:
                _, priority = name.strip("_").split(level)
                self._level = idx
                self._priority = int(priority)
                self._level_priority = self._level * 100 + self._priority
                return

        raise ValueError("Unknown level in %s" % name)
=======
    def __init__(self, level, priority):
        for idx, level_name in enumerate(_DEVICE_INIT_LEVELS):
            if level_name == level:
                self._level = idx
                self._priority = priority
                # Tuples compare elementwise in order
                self._level_priority = (self._level, self._priority)
                return

        raise ValueError("Unknown level in %s" % level)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

    def __repr__(self):
        return "<%s %s %d>" % (self.__class__.__name__,
                               _DEVICE_INIT_LEVELS[self._level], self._priority)

    def __str__(self):
        return "%s %d" % (_DEVICE_INIT_LEVELS[self._level], self._priority)

    def __lt__(self, other):
        return self._level_priority < other._level_priority

    def __eq__(self, other):
        return self._level_priority == other._level_priority

    def __hash__(self):
        return self._level_priority


<<<<<<< HEAD
class ZephyrObjectFile:
    """Load an object file and finds the device defined within it.

    Load an object file and scans the relocation sections looking for the known
    ones containing initialization callbacks. Then finds what device ordinals
    are being initialized at which priority and stores the list internally.

    A dictionary of {ordinal: Priority} is available in the defined_devices
    class variable.
=======
class ZephyrInitLevels:
    """Load an executable file and find the initialization calls and devices.

    Load a Zephyr executable file and scan for the list of initialization calls
    and defined devices.

    The list of devices is available in the "devices" class variable in the
    {ordinal: Priority} format, the list of initilevels is in the "initlevels"
    class variables in the {"level name": ["call", ...]} format.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

    Attributes:
        file_path: path of the file to be loaded.
    """
    def __init__(self, file_path):
        self.file_path = file_path
        self._elf = ELFFile(open(file_path, "rb"))
<<<<<<< HEAD
        self._load_symbols()
        self._find_defined_devices()

    def _load_symbols(self):
        """Initialize the symbols table."""
        self._symbols = {}
=======
        self._load_objects()
        self._load_level_addr()
        self._process_initlevels()

    def _load_objects(self):
        """Initialize the object table."""
        self._objects = {}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

        for section in self._elf.iter_sections():
            if not isinstance(section, SymbolTableSection):
                continue

<<<<<<< HEAD
            for num, sym in enumerate(section.iter_symbols()):
                if sym.name:
                    self._symbols[num] = sym.name

    def _device_ord_from_rel(self, rel):
        """Find a device ordinal from a device symbol name."""
        sym_id = rel["r_info_sym"]
        sym_name = self._symbols.get(sym_id, None)

=======
            for sym in section.iter_symbols():
                if (sym.name and
                    sym.entry.st_size > 0 and
                    sym.entry.st_info.type in ["STT_OBJECT", "STT_FUNC"]):
                    self._objects[sym.entry.st_value] = (
                            sym.name, sym.entry.st_size, sym.entry.st_shndx)

    def _load_level_addr(self):
        """Find the address associated with known init levels."""
        self._init_level_addr = {}

        for section in self._elf.iter_sections():
            if not isinstance(section, SymbolTableSection):
                continue

            for sym in section.iter_symbols():
                for level in _DEVICE_INIT_LEVELS:
                    name = f"__init_{level}_start"
                    if sym.name == name:
                        self._init_level_addr[level] = sym.entry.st_value
                    elif sym.name == "__init_end":
                        self._init_level_end = sym.entry.st_value

        if len(self._init_level_addr) != len(_DEVICE_INIT_LEVELS):
            raise ValueError(f"Missing init symbols, found: {self._init_level_addr}")

        if not self._init_level_end:
            raise ValueError(f"Missing init section end symbol")

    def _device_ord_from_name(self, sym_name):
        """Find a device ordinal from a symbol name."""
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
        if not sym_name:
            return None

        if not sym_name.startswith(_DEVICE_ORD_PREFIX):
            return None

        _, device_ord = sym_name.split(_DEVICE_ORD_PREFIX)
        return int(device_ord)

<<<<<<< HEAD
    def _find_defined_devices(self):
        """Find the device structures defined in the object file."""
        self.defined_devices = {}

        for section in self._elf.iter_sections():
            if not isinstance(section, RelocationSection):
                continue

            if not section.name.startswith(_INIT_SECTION_PREFIX):
                continue

            prio = Priority(section.name)

            for rel in section.iter_relocations():
                device_ord = self._device_ord_from_rel(rel)
                if not device_ord:
                    continue

                if device_ord in self.defined_devices:
                    raise ValueError(
                            f"Device {device_ord} already defined, stale "
                            "object files in the build directory? "
                            "Try running a clean build.")

                self.defined_devices[device_ord] = prio

    def __repr__(self):
        return (f"<{self.__class__.__name__} {self.file_path} "
                f"defined_devices: {self.defined_devices}>")
=======
    def _object_name(self, addr):
        if not addr:
            return "NULL"
        elif addr in self._objects:
            return self._objects[addr][0]
        else:
            return "unknown"

    def _initlevel_pointer(self, addr, idx, shidx):
        elfclass = self._elf.elfclass
        if elfclass == 32:
            ptrsize = 4
        elif elfclass == 64:
            ptrsize = 8
        else:
            ValueError(f"Unknown pointer size for ELF class f{elfclass}")

        section = self._elf.get_section(shidx)
        start = section.header.sh_addr
        data = section.data()

        offset = addr - start

        start = offset + ptrsize * idx
        stop = offset + ptrsize * (idx + 1)

        return int.from_bytes(data[start:stop], byteorder="little")

    def _process_initlevels(self):
        """Process the init level and find the init functions and devices."""
        self.devices = {}
        self.initlevels = {}

        for i, level in enumerate(_DEVICE_INIT_LEVELS):
            start = self._init_level_addr[level]
            if i + 1 == len(_DEVICE_INIT_LEVELS):
                stop = self._init_level_end
            else:
                stop = self._init_level_addr[_DEVICE_INIT_LEVELS[i + 1]]

            self.initlevels[level] = []

            priority = 0
            addr = start
            while addr < stop:
                if addr not in self._objects:
                    raise ValueError(f"no symbol at addr {addr:08x}")
                obj, size, shidx = self._objects[addr]

                arg0_name = self._object_name(self._initlevel_pointer(addr, 0, shidx))
                arg1_name = self._object_name(self._initlevel_pointer(addr, 1, shidx))

                self.initlevels[level].append(f"{obj}: {arg0_name}({arg1_name})")

                ordinal = self._device_ord_from_name(arg1_name)
                if ordinal:
                    prio = Priority(level, priority)
                    self.devices[ordinal] = prio

                addr += size
                priority += 1
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

class Validator():
    """Validates the initialization priorities.

    Scans through a build folder for object files and list all the device
    initialization priorities. Then compares that against the EDT derived
    dependency list and log any found priority issue.

    Attributes:
<<<<<<< HEAD
        build_dir: the build directory to scan
        edt_pickle_path: path of the EDT pickle file
        log: a logging.Logger object
    """
    def __init__(self, build_dir, edt_pickle_path, log):
        self.log = log

        edtser = pathlib.Path(build_dir, edt_pickle_path)
        with open(edtser, "rb") as f:
=======
        elf_file_path: path of the ELF file
        edt_pickle: name of the EDT pickle file
        log: a logging.Logger object
    """
    def __init__(self, elf_file_path, edt_pickle, log):
        self.log = log

        edt_pickle_path = pathlib.Path(
                pathlib.Path(elf_file_path).parent,
                edt_pickle)
        with open(edt_pickle_path, "rb") as f:
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
            edt = pickle.load(f)

        self._ord2node = edt.dep_ord2node

<<<<<<< HEAD
        self._objs = []
        for file in self._find_build_objfiles(build_dir, is_root=True):
            obj = ZephyrObjectFile(file)
            if obj.defined_devices:
                self._objs.append(obj)
                for dev in obj.defined_devices:
                    dev_path = self._ord2node[dev].path
                    self.log.debug(f"{file}: {dev_path}")

        self._dev_priorities = {}
        for obj in self._objs:
            for dev, prio in obj.defined_devices.items():
                if dev in self._dev_priorities:
                    dev_path = self._ord2node[dev].path
                    raise ValueError(
                            f"ERROR: device {dev} ({dev_path}) already defined")
                self._dev_priorities[dev] = prio
=======
        self._obj = ZephyrInitLevels(elf_file_path)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

        self.warnings = 0
        self.errors = 0

<<<<<<< HEAD
    def _find_build_objfiles(self, build_dir, is_root=False):
        """Find all project object files, skip sub-build directories."""
        if not is_root and pathlib.Path(build_dir, _BUILD_DIR_DETECT_FILE).exists():
            return

        for file in pathlib.Path(build_dir).iterdir():
            if file.is_file() and file.name.endswith(_OBJ_FILE_SUFFIX):
                yield file
            if file.is_dir():
                for file in self._find_build_objfiles(file.resolve()):
                    yield file

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    def _check_dep(self, dev_ord, dep_ord):
        """Validate the priority between two devices."""
        if dev_ord == dep_ord:
            return

        dev_node = self._ord2node[dev_ord]
        dep_node = self._ord2node[dep_ord]

<<<<<<< HEAD
=======
        if dev_node._binding:
            dev_compat = dev_node._binding.compatible
            if dev_compat in _IGNORE_COMPATIBLES:
                self.log.info(f"Ignoring priority: {dev_node._binding.compatible}")
                return

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
        if dev_node._binding and dep_node._binding:
            dev_compat = dev_node._binding.compatible
            dep_compat = dep_node._binding.compatible
            if (dev_compat, dep_compat) in _INVERTED_PRIORITY_COMPATIBLES:
                self.log.info(f"Swapped priority: {dev_compat}, {dep_compat}")
                dev_ord, dep_ord = dep_ord, dev_ord

<<<<<<< HEAD
        dev_prio = self._dev_priorities.get(dev_ord, None)
        dep_prio = self._dev_priorities.get(dep_ord, None)
=======
        dev_prio = self._obj.devices.get(dev_ord, None)
        dep_prio = self._obj.devices.get(dep_ord, None)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

        if not dev_prio or not dep_prio:
            return

        if dev_prio == dep_prio:
            self.warnings += 1
            self.log.warning(
                    f"{dev_node.path} {dev_prio} == {dep_node.path} {dep_prio}")
        elif dev_prio < dep_prio:
            self.errors += 1
            self.log.error(
                    f"{dev_node.path} {dev_prio} < {dep_node.path} {dep_prio}")
        else:
            self.log.info(
                    f"{dev_node.path} {dev_prio} > {dep_node.path} {dep_prio}")

    def _check_edt_r(self, dev_ord, dev):
        """Recursively check for dependencies of a device."""
        for dep in dev.depends_on:
            self._check_dep(dev_ord, dep.dep_ordinal)
        if dev._binding and dev._binding.child_binding:
            for child in dev.children.values():
                if "compatible" in child.props:
                    continue
                if dev._binding.path != child._binding.path:
                    continue
                self._check_edt_r(dev_ord, child)

    def check_edt(self):
        """Scan through all known devices and validate the init priorities."""
<<<<<<< HEAD
        for dev_ord in self._dev_priorities:
            dev = self._ord2node[dev_ord]
            self._check_edt_r(dev_ord, dev)

=======
        for dev_ord in self._obj.devices:
            dev = self._ord2node[dev_ord]
            self._check_edt_r(dev_ord, dev)

    def print_initlevels(self):
        for level, calls in self._obj.initlevels.items():
            print(level)
            for call in calls:
                print(f"  {call}")

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
def _parse_args(argv):
    """Parse the command line arguments."""
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
        allow_abbrev=False)

<<<<<<< HEAD
    parser.add_argument("-d", "--build-dir", default="build",
                        help="build directory to use")
=======
    parser.add_argument("-f", "--elf-file", default=pathlib.Path("build", "zephyr", "zephyr.elf"),
                        help="ELF file to use")
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    parser.add_argument("-v", "--verbose", action="count",
                        help=("enable verbose output, can be used multiple times "
                              "to increase verbosity level"))
    parser.add_argument("-w", "--fail-on-warning", action="store_true",
                        help="fail on both warnings and errors")
    parser.add_argument("--always-succeed", action="store_true",
                        help="always exit with a return code of 0, used for testing")
    parser.add_argument("-o", "--output",
                        help="write the output to a file in addition to stdout")
<<<<<<< HEAD
    parser.add_argument("--edt-pickle", default=pathlib.Path("zephyr", "edt.pickle"),
                        help="path to read the pickled edtlib.EDT object from",
=======
    parser.add_argument("-i", "--initlevels", action="store_true",
                        help="print the initlevel functions instead of checking the device dependencies")
    parser.add_argument("--edt-pickle", default=pathlib.Path("edt.pickle"),
                        help="name of the the pickled edtlib.EDT file",
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
                        type=pathlib.Path)

    return parser.parse_args(argv)

def _init_log(verbose, output):
    """Initialize a logger object."""
    log = logging.getLogger(__file__)

    console = logging.StreamHandler()
    console.setFormatter(logging.Formatter("%(levelname)s: %(message)s"))
    log.addHandler(console)

    if output:
<<<<<<< HEAD
        file = logging.FileHandler(output)
=======
        file = logging.FileHandler(output, mode="w")
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
        file.setFormatter(logging.Formatter("%(levelname)s: %(message)s"))
        log.addHandler(file)

    if verbose and verbose > 1:
        log.setLevel(logging.DEBUG)
    elif verbose and verbose > 0:
        log.setLevel(logging.INFO)
    else:
        log.setLevel(logging.WARNING)

    return log

def main(argv=None):
    args = _parse_args(argv)

    log = _init_log(args.verbose, args.output)

<<<<<<< HEAD
    log.info(f"check_init_priorities build_dir: {args.build_dir}")

    validator = Validator(args.build_dir, args.edt_pickle, log)
    validator.check_edt()
=======
    log.info(f"check_init_priorities: {args.elf_file}")

    validator = Validator(args.elf_file, args.edt_pickle, log)
    if args.initlevels:
        validator.print_initlevels()
    else:
        validator.check_edt()
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

    if args.always_succeed:
        return 0

    if args.fail_on_warning and validator.warnings:
        return 1

    if validator.errors:
        return 1

    return 0

if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
