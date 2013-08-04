/**
 * hyperscan.h
 * (c) 2008 Mohit Soni
 * License: MIT License
 */

#ifndef hyperscan_h_
#define hyperscan_h_

// Header files - START
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// Header files - END

// Constants definition - START
#define MIN_PORT 1
#define MAX_PORT 65535
// Constants definition - END

// Variables declaration - START
int start_port;
int end_port;
int count_port;
int sockfd;
char *ipAddress;
struct sockaddr_in ser;
struct in_addr inp;
// Variables declaration - END

// Functions prototypes - START

/**
 * Name: help
 * Parameters: none
 * Return type: void
 * Description: Print out the help on the usage of hyperscan
 */
void help();

/**
 * Name: validateIP
 * Parameters: 
 * 	(1) Type - char* Name - ip
 *	(2) Type - struct in_addr* Name - inp	
 * Return type: int
 * Return values: 1 - Success, 0 - Failure
 * Description: Validates the ip address
 *
int validateIP(char* ip, struct in_addr* inp);
 */

/**
 * Name: validatePort
 * Parameters: (1) Type - char* Name - p
 * Return type: int
 * Return values: 1 - Success, 0 - Failure
 * Description: Validates the port
 */
int validatePort(char* );

// Functions prototypes - START

#endif
