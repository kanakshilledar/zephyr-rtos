<<<<<<< HEAD
.. _spi-nor-sample:

JEDEC SPI-NOR Sample
####################
=======
.. zephyr:code-sample:: spi-nor
   :name: JEDEC SPI-NOR flash
   :relevant-api: flash_interface

   Use the flash API to interact with an SPI NOR serial flash memory device.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Overview
********

<<<<<<< HEAD
This sample demonstrates using the flash API on a SPI NOR serial flash
=======
This sample demonstrates using the :ref:`flash API <flash_api>` on a SPI NOR serial flash
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
memory device.  While trivial it is an example of direct access and
allows confirmation that the flash is working and that automatic power
savings is correctly implemented.

Building and Running
********************

The application will build only for a target that has a :ref:`devicetree
<dt-guide>` entry with ``jedec,spi-nor`` as a compatible.

.. zephyr-app-commands::
   :zephyr-app: samples/drivers/spi_flash
   :board: nrf52840dk_nrf52840
   :goals: build flash
   :compact:

Sample Output
=============

.. code-block:: console

   *** Booting Zephyr OS build zephyr-v2.3.0-2142-gca01d2e1d748  ***

   JEDEC QSPI-NOR SPI flash testing
   ==========================

   Test 1: Flash erase
   Flash erase succeeded!

   Test 2: Flash write
   Attempting to write 4 bytes
   Data read matches data written. Good!
