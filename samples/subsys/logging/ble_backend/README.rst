<<<<<<< HEAD
.. _logger_ble_backend:

Logging: BLE Backend
########################
=======
.. zephyr:code-sample:: logging-ble-backend
   :name: BLE logging backend
   :relevant-api: log_api log_backend bt_gatt

   Send log messages over BLE using the BLE logging backend.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Overview
********

Sample that demonstrates how to setup and use the BLE Logging backend. The
BLE Logger uses the NRF Connect SDK NUS service as UUID to make it compatible
with already existing apps to debug BLE connections over UART.

<<<<<<< HEAD
=======
The notification size of the ble backend buffer is dependent on the
transmission size of the mtu set with `CONFIG_BT_L2CAP_TX_MTU`. Be sure
to change this configuration to increase the logger throughput over BLE.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Requirements
************

* A board with BLE support

Building and Running
********************

This sample can be found under :zephyr_file:`samples/subsys/logging/ble_backend` in the
Zephyr tree.

The BLE logger can be tested with the NRF Toolbox app or any similar app that can connect over
BLE and detect the NRF NUS UUID service.
