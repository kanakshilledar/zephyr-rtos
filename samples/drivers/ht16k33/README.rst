<<<<<<< HEAD
.. _ht16k33:

HT16K33 LED driver with keyscan
###############################
=======
.. zephyr:code-sample:: ht16k33
   :name: HT16K33 LED driver with keyscan
   :relevant-api: led_interface kscan_interface

   Control up to 128 LEDs connected to an HT16K33 LED driver and log keyscan events.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Overview
********

This sample controls the LEDs connected to a `Holtek HT16K33`_
driver. The sample supports up to 128 LEDs connected to the
rows/columns of the HT16K33.

The LEDs are controlled using the following pattern:

 1. turn on all connected (up to 128) LEDs one-by-one
 2. blink the LEDs at 2 Hz, 1 Hz, and 0.5 Hz
 3. reduce the brightness gradually from 100% to 0%
 4. turn off all LEDs, restore 100% brightness, and start over

The sample logs keyscan events on the console.

Building and Running
********************

Build the application for the :ref:`nrf52840dk_nrf52840` board, and
<<<<<<< HEAD
connect a HT16K33 LED driver at address 0x70 on the I2C-0 bus.
=======
connect an HT16K33 LED driver at address 0x70 on the I2C-0 bus.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

.. zephyr-app-commands::
   :zephyr-app: samples/drivers/ht16k33
   :board: nrf52840dk_nrf52840
   :goals: build
   :compact:

For flashing the application, refer to the Flashing section of the
:ref:`nrf52840dk_nrf52840` board documentation.

References
**********

.. target-notes::

.. _Holtek HT16K33: http://www.holtek.com/productdetail/-/vg/HT16K33
