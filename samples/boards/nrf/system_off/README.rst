.. _nrf-system-off-sample:

nRF5x System Off demo
#####################

Overview
********

This sample can be used for basic power measurement and as an example of
<<<<<<< HEAD
deep sleep on Nordic platforms.  The functional behavior is:

* Busy-wait for 2 seconds
* Sleep for 2 seconds without device power control
* Sleep for 2 seconds after turning UART off, which reduces current draw
  by a couple hundred uA
* Turn the system off after enabling wakeup through a button press

A power monitor will be able to distinguish among these states.

This sample also demonstrates the use of a :c:func:`SYS_INIT()` call to
disable the deep sleep functionality before the kernel starts, which
prevents the board from powering down during initialization of drivers
that use unbounded delays to wait for startup.
=======
deep sleep on Nordic platforms.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

RAM Retention
=============

On nRF52 platforms this also can demonstrate RAM retention.  By selecting
``CONFIG_APP_RETENTION=y`` state related to number of boots, number of times
system off was entered, and total uptime since initial power-on are retained
in a checksummed data structure.  The POWER peripheral is configured to keep
the containing RAM section powered while in system-off mode.

Requirements
************

This application uses nRF51 DK or nRF52 DK board for the demo.

<<<<<<< HEAD
Building, Flashing and Running
******************************

.. zephyr-app-commands::
   :zephyr-app: samples/boards/nrf52/system_off
   :board: nrf52dk_nrf52832
   :goals: build flash
   :compact:

Running:

1. Open UART terminal.
2. Power Cycle Device.
3. Device will demonstrate two activity levels which can be measured.
4. Device will demonstrate long sleep at minimal non-off power.
5. Device will turn itself off using deep sleep state 1.  Press Button 1
   to wake the device and restart the application as if it had been
   powered back on.

Sample Output
=================
=======
Sample Output
=============

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
nRF52 core output
-----------------

.. code-block:: console

   *** Booting Zephyr OS build v2.3.0-rc1-204-g5f2eb85f728d  ***

   nrf52dk_nrf52832 system off demo
<<<<<<< HEAD
   Busy-wait 2 s
   Busy-wait 2 s with UART off
   Sleep 2 s
   Sleep 2 s with UART off
   Entering system off; press BUTTON1 to restart
=======
   Entering system off; press sw0 to restart
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
