.. _bluetooth_mesh_models_op_agg_srv:

Opcodes Aggregator Server
#########################

The Opcodes Aggregator Server model is a foundation model defined by the Bluetooth
<<<<<<< HEAD
mesh specification. It is an optional model, enabled with the :kconfig:option:`CONFIG_BT_MESH_OP_AGG_SRV` option.

The Opcodes Aggregator Server model is introduced in the Bluetooth Mesh Profile
=======
mesh specification. It is an optional model, enabled with the
:kconfig:option:`CONFIG_BT_MESH_OP_AGG_SRV` option.

The Opcodes Aggregator Server model is introduced in the Bluetooth Mesh Protocol
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
Specification version 1.1, and is used to support the functionality of processing
a sequence of access layer messages.

The Opcodes Aggregator Server model accepts messages encrypted with the node's device key
or the application keys.

<<<<<<< HEAD
The Opcodes Aggregator Server model can only be instantiated on the
node's primary element.
=======
If present, the Opcodes Aggregator Server model must only be instantiated on the primary element.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

The targeted server models should be bound to the same application key that is used
to encrypt the sequence of access layer messages sent to the Opcodes Aggregator Server.

The Opcodes Aggregator Server handles aggregated messages and dispatches them to the
respective models and their message handlers. Current implementation assumes that
responses are sent from the same execution context as the received message and
doesn't allow to send a postponed response, for example from a work queue.

API reference
*************

.. doxygengroup:: bt_mesh_op_agg_srv
   :project: Zephyr
   :members:
