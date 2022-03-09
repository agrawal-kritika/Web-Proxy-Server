#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>

int main()
{
	/* create a file object to hold information from file and read */
	FILE *html_data;
	html_data = fopen("index.html" , "r");

	/*string to store the html of the file */
	char response_data[2048] = {'\0'};
        char buffer[128];	
	while(fgets(buffer, sizeof(buffer), html_data))
	{
		strcat(response_data, buffer);
	}


	/* set the status code. ie the http response */
	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";


	/* combine the response body (html file) & the response header (http header) */
	strcat(http_header, response_data);

	/* create a server socket */
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* define the address structure */
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8080);
	server_address.sin_addr.s_addr = INADDR_ANY;

	/* bind the socket */
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	/* listen for connections on the socket */
	listen(server_socket, 5);


	/* create a placeholder for the client socket that is going to get opened */
	int client_socket;

	while(1)
	{
		client_socket = accept(server_socket, NULL, NULL);
		send(client_socket , http_header, sizeof(http_header), 0);
		close(client_socket);
	}

	return 0;
}
