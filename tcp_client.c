#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h> //to store the address info

int main()
{
	//create a socket
	int network_socket;  /* to hold the socket descriptor, ie., info about our socket */
        network_socket = socket(AF_INET, SOCK_STREAM, 0); /* AF_INET->domain of socket, SOCK_STREAM->type of socket, 0->protocol used(TCP) */

	//specify an adress for the socket
	struct sockaddr_in server_addr;  
	serveraddr.sin_family = AF_INET;  // set the family of the address to know the type of address we are working with.
        server_addr.sin_port = htons(9002);        //specify the port that we are going to connect to	
	return 0;
}
