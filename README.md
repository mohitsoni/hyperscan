## HyperScan - A port scanner

* [Introduction](#introduction)
* [Installation](#installation)
* [How to use](#how-to-use)
* [Limitations](#limitations)

### Introduction
HyperScan is a port scanner. It can be used to check the status of the ports on a given host. HyperScan is optimized to work on multicore processors for better performance.

### Installation
Follow the steps given below to install HyperScan on your system:

1. Clone the git repository
2. Change your directory to hyperscan directory.
3. Use 'make' to compile hyperscan.
4. As a super user, use 'make install' to install hyperscan on your scan.

### How to use ?
Given below the format in which the hyperscan should be invoked. Usage:

```
hyperscan <ip-address> <start port> <end port>
```

* ip-address - It is the ip-address of the host you want to scan
* start-port - It is the port from which you want to start your port scanning
* end-port   - It is the port at which you want to stop you port scanning

You can get usage help anytime by typing hyperscan alone any time.

### Limitations
The following are the limitations that I would try to overcome in the future releases:

1. Requires IP address of the host, will not work correct if domain name is given
2. It works only in command mode right now. In future I will introduce a graphical front end to it.
