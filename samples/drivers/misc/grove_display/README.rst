<<<<<<< HEAD
.. _grove-lcd-sample:

Grove LCD
#########
=======
.. zephyr:code-sample:: grove-lcd
   :name: Grove LCD
   :relevant-api: grove_display

   Display an incrementing counter and change the backlight color.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Overview
********

This sample displays an incrementing counter through the Grove LCD, with
changing backlight.

Requirements
************

To use this sample, the following hardware is required:

* A board with ADC support
* `Grove LCD module`_
* `Grove Base Shield`_ [Optional]

Wiring
******

You will need to connect the Grove LCD via the Grove shield onto a board that
supports Arduino shields.

On some boards you will need to use 2 pull-up resistors (10k Ohm) between the
SCL/SDA lines and 3.3V.

Take note that even though SDA and SCL are connected to a 3.3V power source, the
Grove LCD VDD line needs to be connected to the 5V power line, otherwise
characters will not be displayed on the LCD (3.3V is enough to power just the
backlight).


Building and Running
********************

This sample should work on any board that has I2C enabled and has an Arduino
shield interface. For example, it can be run on the FRDM K64F board as
described below:

.. zephyr-app-commands::
<<<<<<< HEAD
   :zephyr-app: samples/subsys/display/grove_display
=======
   :zephyr-app: samples/drivers/misc/grove_display
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
   :board: frdm_k64f
   :goals: flash
   :compact:

.. _Grove Base Shield: https://wiki.seeedstudio.com/Base_Shield_V2/
.. _Grove LCD module: http://wiki.seeed.cc/Grove-LCD_RGB_Backlight/
