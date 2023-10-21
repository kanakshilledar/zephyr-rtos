<<<<<<< HEAD
.. _samples_edac:

EDAC Shell Sample
#################
=======
.. zephyr:code-sample:: edac
   :name: EDAC shell
   :relevant-api: edac

   Test error detection and correction (EDAC) using shell commands.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Overview
********

<<<<<<< HEAD
This sample demonstrates the EDAC driver API in a simple EDAC shell sample.
=======
This sample demonstrates the :ref:`EDAC driver API <edac_api>` in a simple EDAC shell sample.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Building and Running
********************

<<<<<<< HEAD
This project can be built and executed on as following example for the
:ref:`ehl_crb` board:
=======
This sample can be found under :zephyr_file:`samples/subsys/edac` in the
Zephyr tree.
The sample can be built as follows for the :ref:`intel_ehl_crb` board:
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

.. zephyr-app-commands::
   :zephyr-app: samples/subsys/edac
   :host-os: unix
<<<<<<< HEAD
   :board: ehl_crb
   :goals: run
   :compact:

=======
   :board: intel_ehl_crb
   :goals: build
   :compact:

The Zephyr image that's created can be run on the :ref:`intel_ehl_crb` board
as per the instructions in the board documentation. Check out the
:ref:`intel_ehl_crb` for details.

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
Sample output
*************

Getting help
============

After the application has started help can be read with the following
<<<<<<< HEAD
command::
=======
command:

.. code-block:: console
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

   uart:~$ edac -h
   edac - EDAC information
   Subcommands:
     info    :Show EDAC information
              edac info <subcommands>
     inject  :Inject ECC error commands
              edac inject <subcommands>

<<<<<<< HEAD
Help for subcommand info can be read with::
=======
Help for subcommand info can be read with:

.. code-block:: console
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

   uart:~$ edac info -h
   info - Show EDAC information
          edac info <subcommands>
   Subcommands:
     ecc_error     :ECC Error Show / Clear commands
     parity_error  :Parity Error Show / Clear commands

<<<<<<< HEAD
Injection help can be received with::
=======
Injection help can be received with:

.. code-block:: console
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

   uart:~$ edac inject -h
   inject - Inject ECC error commands
            edac inject <subcommands>
   Subcommands:
     addr          :Get / Set physical address
     mask          :Get / Set address mask
     trigger       :Trigger injection
     error_type    :Get / Set injection error type
     disable_nmi   :Disable NMI
     enable_nmi    :Enable NMI
     test_default  :Test default injection parameters

Testing Error Injection
=======================

<<<<<<< HEAD
Set Error Injection parameters with::
=======
Set Error Injection parameters with:

.. code-block:: console
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

   uart:~$ edac inject addr 0x1000
   Set injection address base to: 0x1000

   uart:~$ edac inject mask 0x7fffffffc0
   Set injection address mask to 7fffffffc0

   uart:~$ edac inject error_type correctable
   Set injection error type: correctable

<<<<<<< HEAD
Trigger injection with::
=======
Trigger injection with:

.. code-block:: console
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

   uart:~$ edac inject trigger
   Triggering injection

Now Read / Write to the injection address to trigger Error Injection with
<<<<<<< HEAD
following devmem commands::
=======
following devmem commands:

.. code-block:: console
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

   uart:~$ devmem 0x1000 32 0xabcd
   Mapped 0x1000 to 0x2ffcf000

   Using data width 32
   Writing value 0xabcd

   uart:~$ devmem 0x1000
   Mapped 0x1000 to 0x2ffce000

   Using data width 32
   Read value 0xabcd

<<<<<<< HEAD
We should get the following message on screen indicating an IBECC event::
=======
We should get the following message on screen indicating an IBECC event:

.. code-block:: none
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

   Got notification about IBECC event
