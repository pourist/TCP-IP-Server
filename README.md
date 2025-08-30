# TCP Server Framework

## Description

A modular TCP server implementation in C++ designed to manage multiple clients concurrently using thread-based services and a central controller. The project demonstrates scalable socket programming with clear separation of concerns and thread coordination.

## Features

* [ ] Central controller to manage services and client lifecycle
* [ ] Connection Acceptor Service (CAS) – accepts new client connections
* [ ] Data Request Service (DRS) – multiplexes I/O, handles client read/write
* [ ] Client Database (ClientDB) – shared structure storing client information
* [ ] Graceful startup and shutdown with thread signaling
* [ ] Message demarcation strategies (fixed/variable size)
* [ ] Keep-alive and connection liveness detection
* [ ] Client migration between multiplexed and multi-threaded modes


