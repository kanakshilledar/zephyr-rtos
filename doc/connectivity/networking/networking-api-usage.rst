.. _networking_api_usage:

Network Connectivity API
########################

Applications should use the BSD socket API defined in
:zephyr_file:`include/zephyr/net/socket.h` to create a connection, send or receive data,
and close a connection. The same API can be used when working with UDP or
TCP data. See :ref:`BSD socket API <bsd_sockets_interface>` for more details.

<<<<<<< HEAD
See :ref:`sockets-echo-server-sample` and :ref:`sockets-echo-client-sample`
applications how to create a simple server or client BSD socket based
=======
See :zephyr:code-sample:`sockets-echo-server` and :zephyr:code-sample:`sockets-echo-client`
sample applications to learn how to create a simple server or client BSD socket based
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
application.

The legacy connectivity API in :zephyr_file:`include/zephyr/net/net_context.h` should not be
used by applications.
