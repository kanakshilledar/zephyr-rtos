<<<<<<< HEAD
.. _character_frame_buffer_sample:

Character frame buffer
######################
=======
.. zephyr:code-sample:: character-frame-buffer
   :name: Character frame buffer
   :relevant-api: monochrome_character_framebuffer

   Display character strings using the Character Frame Buffer (CFB).
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Overview
********

This sample displays character strings using the Character Frame Buffer
(CFB) subsystem framework.

Requirements
************

This sample requires a supported board and CFB-supporting
display, such as the :ref:`reel_board`.

Building and Running
********************

Build this sample application with the following commands:

.. zephyr-app-commands::
   :zephyr-app: samples/subsys/display/cfb
   :board: reel_board
   :goals: build
   :compact:

See :ref:`reel_board` on how to flash the build.
