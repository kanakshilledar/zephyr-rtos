.. _message_queues_v2:

Message Queues
##############

A :dfn:`message queue` is a kernel object that implements a simple
message queue, allowing threads and ISRs to asynchronously send and receive
fixed-size data items.

.. contents::
    :local:
    :depth: 2

Concepts
********

Any number of message queues can be defined (limited only by available RAM).
Each message queue is referenced by its memory address.

A message queue has the following key properties:

* A **ring buffer** of data items that have been sent but not yet received.

* A **data item size**, measured in bytes.

* A **maximum quantity** of data items that can be queued in the ring buffer.

<<<<<<< HEAD
The message queue's ring buffer must be aligned to an N-byte boundary, where
N is a power of 2 (i.e. 1, 2, 4, 8, ...). To ensure that the messages stored in
the ring buffer are similarly aligned to this boundary, the data item size
must also be a multiple of N.

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
A message queue must be initialized before it can be used.
This sets its ring buffer to empty.

A data item can be **sent** to a message queue by a thread or an ISR.
The data item pointed at by the sending thread is copied to a waiting thread,
if one exists; otherwise the item is copied to the message queue's ring buffer,
if space is available. In either case, the size of the data area being sent
*must* equal the message queue's data item size.

If a thread attempts to send a data item when the ring buffer is full,
the sending thread may choose to wait for space to become available.
Any number of sending threads may wait simultaneously when the ring buffer
is full; when space becomes available
it is given to the highest priority sending thread that has waited the longest.

A data item can be **received** from a message queue by a thread.
The data item is copied to the area specified by the receiving thread;
the size of the receiving area *must* equal the message queue's data item size.

If a thread attempts to receive a data item when the ring buffer is empty,
the receiving thread may choose to wait for a data item to be sent.
Any number of receiving threads may wait simultaneously when the ring buffer
is empty; when a data item becomes available it is given to
the highest priority receiving thread that has waited the longest.

A thread can also **peek** at the message on the head of a message queue without
removing it from the queue.
The data item is copied to the area specified by the receiving thread;
the size of the receiving area *must* equal the message queue's data item size.

.. note::
    The kernel does allow an ISR to receive an item from a message queue,
    however the ISR must not attempt to wait if the message queue is empty.

<<<<<<< HEAD
=======
.. note::
    Alignment of the message queue's ring buffer is not necessary.
    The underlying implementation uses :c:func:`memcpy` (which is
    alignment-agnostic) and does not expose any internal pointers.

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
Implementation
**************

Defining a Message Queue
========================

A message queue is defined using a variable of type :c:struct:`k_msgq`.
It must then be initialized by calling :c:func:`k_msgq_init`.

The following code defines and initializes an empty message queue
that is capable of holding 10 items, each of which is 12 bytes long.

.. code-block:: c

    struct data_item_type {
        uint32_t field1;
	uint32_t field2;
	uint32_t field3;
    };

<<<<<<< HEAD
    char __aligned(4) my_msgq_buffer[10 * sizeof(struct data_item_type)];
=======
    char my_msgq_buffer[10 * sizeof(struct data_item_type)];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    struct k_msgq my_msgq;

    k_msgq_init(&my_msgq, my_msgq_buffer, sizeof(struct data_item_type), 10);

Alternatively, a message queue can be defined and initialized at compile time
by calling :c:macro:`K_MSGQ_DEFINE`.

The following code has the same effect as the code segment above. Observe
that the macro defines both the message queue and its buffer.

.. code-block:: c

<<<<<<< HEAD
    K_MSGQ_DEFINE(my_msgq, sizeof(struct data_item_type), 10, 4);

The following code demonstrates an alignment implementation for the
structure defined in the previous example code. ``aligned`` means each
:c:struct:`data_item_type` will begin on the specified byte boundary.
``aligned(4)`` means that the structure is aligned to an address that
is divisible by 4.

.. code-block:: c

    typedef struct {
        uint32_t field1;
	uint32_t field2;
	uint32_t field3;
    }__attribute__((aligned(4))) data_item_type;

=======
    K_MSGQ_DEFINE(my_msgq, sizeof(struct data_item_type), 10, 1);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

Writing to a Message Queue
==========================

A data item is added to a message queue by calling :c:func:`k_msgq_put`.

The following code builds on the example above, and uses the message queue
to pass data items from a producing thread to one or more consuming threads.
If the message queue fills up because the consumers can't keep up, the
producing thread throws away all existing data so the newer data can be saved.

.. code-block:: c

    void producer_thread(void)
    {
        struct data_item_type data;

        while (1) {
            /* create data item to send (e.g. measurement, timestamp, ...) */
            data = ...

            /* send data to consumers */
            while (k_msgq_put(&my_msgq, &data, K_NO_WAIT) != 0) {
                /* message queue is full: purge old data & try again */
                k_msgq_purge(&my_msgq);
            }

            /* data item was successfully added to message queue */
        }
    }

Reading from a Message Queue
============================

A data item is taken from a message queue by calling :c:func:`k_msgq_get`.

The following code builds on the example above, and uses the message queue
to process data items generated by one or more producing threads. Note that
the return value of :c:func:`k_msgq_get` should be tested as ``-ENOMSG``
can be returned due to :c:func:`k_msgq_purge`.

.. code-block:: c

    void consumer_thread(void)
    {
        struct data_item_type data;

        while (1) {
            /* get a data item */
            k_msgq_get(&my_msgq, &data, K_FOREVER);

            /* process data item */
            ...
        }
    }


Peeking into a Message Queue
============================

A data item is read from a message queue by calling :c:func:`k_msgq_peek`.

The following code peeks into the message queue to read the data item at the
head of the queue that is generated by one or more producing threads.

.. code-block:: c

    void consumer_thread(void)
    {
        struct data_item_type data;

        while (1) {
            /* read a data item by peeking into the queue */
            k_msgq_peek(&my_msgq, &data);

            /* process data item */
            ...
        }
    }

Suggested Uses
**************

Use a message queue to transfer small data items between threads
in an asynchronous manner.

.. note::
    A message queue can be used to transfer large data items, if desired.
    However, this can increase interrupt latency as interrupts are locked
    while a data item is written or read. The time to write or read a data item
    increases linearly with its size since the item is copied in its entirety
    to or from the buffer in memory. For this reason, it is usually preferable
    to transfer large data items by exchanging a pointer to the data item,
    rather than the data item itself.

    A synchronous transfer can be achieved by using the kernel's mailbox
    object type.

Configuration Options
*********************

Related configuration options:

* None.

API Reference
*************

.. doxygengroup:: msgq_apis
