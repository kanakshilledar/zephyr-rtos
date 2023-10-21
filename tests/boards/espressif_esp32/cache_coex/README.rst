.. _cache_coex_test:

Espressif ESP32 PSRAM/SPI Flash co-existence test
#################################################

Overview
********

This code tests SPI Flash and PSRAM content integrity after multithreaded and concurrent accesses to
a common cache. It does so by allocating a big PSRAM memory chunk and repeatedly filling that region
with a random generated pattern. At the same time, a whole SPI Flash page is updated with another pattern
value. By the end of the thread iterations, both PSRAM and SPI Flash have its contents compared against
expected values to check for integrity.

<<<<<<< HEAD
Building and Running
********************

Make sure you have the ESP32 DevKitC connected over USB port.

.. code-block:: console

   west build -b esp32 tests/boards/espressif_esp32/cache_coex
   west flash --esp-device /dev/ttyUSB0
=======
Supported Boards
****************
- esp32_devkitc_wrover
- esp32s2_saola
- esp32s3_devkitm

Building and Running
********************

Make sure you have the target connected over USB port.

.. code-block:: console

   west build -b <board> tests/boards/espressif_esp32/cache_coex
   west flash && west espressif monitor
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Sample Output
=============

<<<<<<< HEAD
To check output of this test, any serial console program can be used (i.e. on Linux picocom, putty, screen, etc).
This test uses ``minicom`` on the serial port ``/dev/ttyUS0``. The following lines indicate a successful test:

.. code-block:: console

    Running test suite cache_coex_test
    ===================================================================
    START - flash_integrity_test
     PASS - flash_integrity_test in 0.1 seconds
    ===================================================================
    START - ram_integrity_test
     PASS - ram_integrity_test in 0.1 seconds
    ===================================================================
    Test suite cache_coex_test succeeded
    ===================================================================
    PROJECT EXECUTION SUCCESSFUL
=======
.. code-block:: console

	Running TESTSUITE cache_coex
	===================================================================
	START - test_flash_integrity
	PASS - test_flash_integrity in 0.001 seconds
	===================================================================
	START - test_ram_integrity
	PASS - test_ram_integrity in 0.001 seconds
	===================================================================
	START - test_using_spiram
	PASS - test_using_spiram in 0.001 seconds
	===================================================================
	TESTSUITE cache_coex succeeded
	------ TESTSUITE SUMMARY START ------
	SUITE PASS - 100.00% [cache_coex]: pass = 3, fail = 0, skip = 0, total = 3 duration = 0.003 seconds
	- PASS - [cache_coex.test_flash_integrity] duration = 0.001 seconds
	- PASS - [cache_coex.test_ram_integrity] duration = 0.001 seconds
	- PASS - [cache_coex.test_using_spiram] duration = 0.001 seconds
	------ TESTSUITE SUMMARY END ------
	===================================================================
	PROJECT EXECUTION SUCCESSFUL
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
