<<<<<<< HEAD
.. _auxdisplay-sample:

Auxiliary display sample
########################
=======
.. zephyr:code-sample:: auxdisplay
   :name: Auxiliary display
   :relevant-api: auxdisplay_interface

   Output "Hello  World" to an auxiliary display.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Overview
********

<<<<<<< HEAD
This sample shows how to use the auxiliary display drivers by outputting a
sample "Hello World" text to one.
=======
This sample shows how to use the :ref:`auxiliary display driver <auxdisplay_api>`
by outputting a sample "Hello World" text to one.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Building and Running
********************

Note that this sample requires a board with an auxiliary display setup. A
sample overlay is provided for the `nucleo_f746zg` board fly-wired to a Hitachi
HD44780-compatible 20 character by 4 line display. See the overlay file
:zephyr_file:`samples/drivers/auxdisplay/boards/nucleo_f746zg.overlay` for
wiring configuration.

.. zephyr-app-commands::
   :zephyr-app: samples/drivers/auxdisplay
   :host-os: unix
   :board: nucleo_f746zg
   :goals: build flash
   :compact:

If successful, the display will show `Hello World from <board>`.
