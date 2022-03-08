/* client socket consists of:
 * socket() - to create a socket
 * connect() - to create a connection between the client socket and the remote server
 * recv() - to receive data from the server
 * close() - to close the socket */


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
        struct sockaddr_in serveraddr;
        serveraddr.sin_family = AF_INET;          /* set the family of the address to know the type of address we are working with. */
        serveraddr.sin_port = htons(9002);       /*specify the port that we are going to connect to */
        serveraddr.sin_addr.s_addr = INADDR_ANY; /*to connect to a local host address 0.0.0.0 by using library fn INADDR_ANY */


        //calling the connect function
        int connection_status= connect(network_socket, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
        /* connect()  returns an integer to know if the connection is successful or not. if 0-> ok, if-1 -> error with connection */

        if(connection_status == -1)
        {
                printf("\nThere was an error making a connection to the remote socket\n\n");
        }
	
	
	//recv function -> to receive the data from the server.
        char server_response[256];  /* to hold info that we might get from the server */
        recv(network_socket, &server_response, sizeof(server_response), 0);


        //print the server's response
        printf("\nThe server's response is: %s\n", server_response);

        //closing the socket
        close(network_socket);

        return 0;
}


