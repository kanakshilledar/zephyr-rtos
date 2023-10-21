.. _edac_ibecc_tests:

Testing Error Detection and Correction
######################################

<<<<<<< HEAD
Tests verify API and use error injection method to inject
errors.
=======
Tests verify API and use error injection method to inject errors.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Prerequisites
*************

IBECC should be enabled in BIOS. This is usually enabled in the default
BIOS configuration. Verify following is enabled::

<<<<<<< HEAD
   Intel Advanced Menu -> Memory Configuration -> In-Band ECC ->  <Enabled>

Verify also operational mode with::

   Intel Advanced Menu -> Memory Configuration -> In-Band ECC Operation Mode -> 2
=======
:menuselection:`Intel Advanced Menu --> Memory Configuration --> In-Band ECC -->  Enabled`

Verify also operational mode with::

:menuselection:`Intel Advanced Menu --> Memory Configuration --> In-Band ECC Operation Mode --> 2`
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

For injection test Error Injection should be enabled.

Error Injection
===============

IBECC includes a feature to ease the verification effort such as Error
Injection capability. This helps to test the error checking, logging and
reporting mechanism within IBECC.

In order to use Error Injection user need to use BIOS Boot Guard 0 profile.

Additionally Error Injection need to be enabled in the following BIOS menu::

<<<<<<< HEAD
   Intel Advanced Menu -> Memory Configuration -> In-Band ECC Error -> <Enabled>
=======
:menuselection:`Intel Advanced Menu --> Memory Configuration --> In-Band ECC Error --> Enabled`
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

.. note::

   Due to high security risk Error Injection capability should not be
   enabled for production. Due to this reason test has production configuration
   and debug configuration. The main difference is that debug configuration
   includes Error Injection.

Building and Running
********************

<<<<<<< HEAD
This project can be built as follows:

.. zephyr-app-commands::
   :zephyr-app: tests/subsys/edac/ibecc
   :board: ehl_crb
=======
This project can be built as follows for the :ref:`intel_ehl_crb` board:

.. zephyr-app-commands::
   :zephyr-app: tests/subsys/edac/ibecc
   :board: intel_ehl_crb
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
   :goals: build
   :compact:

Sample output
=============

.. code-block:: console

   *** Booting Zephyr OS build zephyr-v3.2.0-747-gd421737f433e  ***
   Running TESTSUITE ibecc
   ===================================================================
   START - test_edac_dummy_api
    PASS - test_edac_dummy_api in 0.001 seconds
   ===================================================================
   START - test_ibecc_initialized
   Test ibecc driver is initialized
    PASS - test_ibecc_initialized in 0.004 seconds
   ===================================================================
   START - test_ibecc_injection
    SKIP - test_ibecc_injection in 0.001 seconds
   ===================================================================
   TESTSUITE ibecc succeeded
