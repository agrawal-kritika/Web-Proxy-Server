#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
	/* declare a character pointer and store the first command-line argument in that pointer */
	char *address = argv[1];

	/* create a TCP Client Socket */
	int client_socket;
	client_socket = socket(AF_INET, SOCK_STREAM, 0);


	/* Connect to an address, ie., creating the address structure */
	struct sockaddr_in remote_address;
	remote_address.sin_family = AF_INET;
	remote_address.sin_port = htons(80);    /* port no. 80 , since most web servers run on that port */

	/* inet_aton() fn converts the address to a string in dots & numbers format (192.168.5.10) and vice-versa */
	inet_aton(address, &remote_address.sin_addr.s_addr); 

	/* connect() function */
	connect(client_socket, (struct sockaddr *) &remote_address, sizeof(remote_address));

	/* create variable for holding request and response */
	char req[] = "GET /  HTTP/1.1\r\n\r\n";     //req[] is going to be our actual http request.
        char response[5000];


	/* send request using send() function */
	send(client_socket, req, sizeof(req), 0);

	/* recv() */
	recv(client_socket, &response, sizeof(response), 0);


	/* print the message received from the server */
	printf("\n Server's Response: %s\n", response);


	/* close the socket */
	close(client_socket);

	return 0;
}



