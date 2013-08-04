/**
 * hyperscan - A port scanner
 * (c) 2008 Mohit Soni
 * License: MIT License
 */

// Header files - START
#include "hyperscan.h"
// Header files - END

/**
 * Name: help()
 * Return type: void
 * Description: Print out the help on the usage of hyperscan
 */
void help()
{
	printf("\nUsage: hyperscan <ip-address> <start port> <end port>\n");
	printf("\nhyperscan, v0.1 - A port scanner");
	printf("\nLicense: GPLv3\n\n");
}

/**
 * Name: validatePort
 * Parameters: (1) Type - char* Name - p
 * Return type: int
 * Return values: 1 - Success, 0 - Failure
 * Description: Validates the port
 */
int validatePort(char* p)
{
	int port = atoi(p);
	if(port >=MIN_PORT && port <= MAX_PORT)
		return 1;
	else
		return 0;		
}

int main(int argc, char** argv)
{

	// Declaring variables
	int i;

	// Initializing variables
	i = sockfd = count_port = 0;

	//  Validation Section - START
	
	// Checking the number of arguments passed
	if(argc < 4)
	{
		help();
		exit(EXIT_FAILURE);
	}

	// Validating the IP address
	if(inet_aton(argv[1], &inp) == 0)
	{
		printf("Error: Invalid IP address\n");
		exit(EXIT_FAILURE);
	}

	// Validating the start port
	if(validatePort(argv[2]) == 0)
	{
		printf("Error: Invalid start port number\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		start_port = atoi(argv[2]);
	}

	// Validating the end port
	if(validatePort(argv[3]) == 0)
	{
		printf("Error: Invalid end port number\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		end_port = atoi(argv[3]);
	}

	// Validation Section - END

	sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(sockfd < 0)
	{
		printf("\nError: Unable to create socket\n");
		exit(EXIT_FAILURE);
	}
	
	printf("\nScanning started...");
	printf("\nHost: %s", argv[1]);
	
	ser.sin_addr.s_addr = inp.s_addr;
	ser.sin_family = AF_INET;

	for( i = start_port ; i <= end_port ; i++ )
	{
		ser.sin_port = htons(i);
		if( connect(sockfd, (struct sockaddr *)&ser, sizeof(ser)) == 0 )
		{
			count_port++;
			printf("\nPort(%d) - open", i);
			close(sockfd);
			sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
			if(sockfd < 0)
			{
				printf("\nError: Unable to create socket\n");
				exit(EXIT_FAILURE);
			}
		}
	}

	printf("\nNumber of TCP ports open: %d\n\n", count_port);
	close(sockfd);

	return 0;
}
