.. _hts221:

HTS221: Temperature and Humidity Monitor
########################################

Overview
********
This sample periodically reads temperature and humidity from the HTS221
Temperature & Humidity Sensor and displays it on the console


Requirements
************

This sample uses the HTS221 sensor controlled using the I2C interface.

References
**********

<<<<<<< HEAD
 - HTS211: http://www.st.com/en/mems-and-sensors/hts221.html
=======
 - HTS211: https://www.st.com/en/mems-and-sensors/hts221.html
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Building and Running
********************

 This project outputs sensor data to the console. It requires an HTS221
 sensor, which is present on the disco_l475_iot1 board.

.. zephyr-app-commands::
   :zephyr-app: samples/sensor/hts221
   :board: disco_l475_iot1
   :goals: build
   :compact:

Sample Output
=============

 .. code-block:: console

    Temperature:25.3 C
    Relative Humidity:40%
    Temperature:25.3 C
    Relative Humidity:40%
    Temperature:25.3 C
    Relative Humidity:40%
    Temperature:25.3 C
    Relative Humidity:40%

    <repeats endlessly every 2 seconds>
