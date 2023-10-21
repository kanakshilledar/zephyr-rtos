.. _mcux_acmp:

NXP MCUX Analog Comparator (ACMP)
#################################

Overview
********

This sample show how to use the NXP MCUX Analog Comparator (ACMP) driver. The
sample supports the :ref:`twr_ke18f`, :ref:`mimxrt1170_evk`.

<<<<<<< HEAD
The input voltage for the the negative input of the analog comparator is
=======
The input voltage for the negative input of the analog comparator is
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
provided by the ACMP Digital-to-Analog Converter (DAC). The input voltage for
the positive input can be adjusted by turning the on-board potentiometer for
:ref:`twr_ke18f` board, for :ref:`mimxrt1170_evk` the voltage signal is
captured on J25-13, need change the external voltage signal to check the
output.

The output value of the analog comparator is reported on the console.

Building and Running
********************

Building and Running for TWR-KE18F
==================================
Build the application for the :ref:`twr_ke18f` board, and adjust the
ACMP input voltage by turning the on-board potentiometer.

.. zephyr-app-commands::
<<<<<<< HEAD
   :zephyr-app: samples/drivers/mcux_acmp
=======
   :zephyr-app: samples/sensor/mcux_acmp
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
   :board: twr_ke18f
   :goals: flash
   :compact:

Building and Running for MIMXRT1170-EVK
=======================================
Build the application for the MIMXRT1170-EVK board, and adjust the
ACMP input voltage by changing the voltage input to J25-13.

.. zephyr-app-commands::
<<<<<<< HEAD
   :zephyr-app: samples/drivers/mcux_acmp
=======
   :zephyr-app: samples/sensor/mcux_acmp
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
   :board: mimxrt1170_evk_cm7
   :goals: flash
   :compact:
