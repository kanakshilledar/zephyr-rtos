zephyr_library()

<<<<<<< HEAD
zephyr_library_sources(pcie.c)
=======
zephyr_library_sources(pcie.c vc.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library_sources_ifdef(CONFIG_PCIE_CONTROLLER controller.c)
zephyr_library_sources_ifdef(CONFIG_PCIE_ECAM pcie_ecam.c)
zephyr_library_sources_ifdef(CONFIG_PCIE_MSI msi.c)
zephyr_library_sources_ifdef(CONFIG_PCIE_SHELL shell.c)
zephyr_library_sources_ifdef(CONFIG_PCIE_PTM ptm.c)
