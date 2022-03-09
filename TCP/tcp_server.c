#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>   

int main()
{
	/* create a string to hold the data that is to be sent to all the clients */
	char  server_message[256] = "WELCOME,THIS IS THE SERVER!";

	/* create a server socket -> an integer to hold the return value of our socket call */
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* defining the server address */
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	/* call the bind() function */
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	/* call the listen function to start listening for connections */
	listen(server_socket, 5);  /* setting the backlog as 5 (the least, since we are dealing with one particular client program) */

	/* create an integer to hold the client socket */
	int client_socket;

	/* call the accept() function & set the return value to the client socket */
	client_socket = accept(server_socket, NULL, NULL);
	
	/* send message to our client socket */
	send(client_socket, server_message, sizeof(server_message), 0);

	/* close the socket */
	close(server_socket);

	return 0;
}
