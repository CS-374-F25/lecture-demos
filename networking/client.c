#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	/*
	struct sockaddr_in server_address = {0};
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(443);
	*/

	struct addrinfo address_hints = {0};
	address_hints.ai_family = AF_INET;
	address_hints.ai_socktype = SOCK_STREAM;
	address_hints.ai_protocol = 0;

	struct addrinfo* results = NULL;
	int getaddrinfo_result = getaddrinfo("google.com", "443", &address_hints, &results);
	if (getaddrinfo_result != 0) {
		printf("Error! Failed to return address information for google.com\n");
	}

	struct addrinfo* itr = results;
	int connect_result = -1;
	while (itr != NULL) {
		// Try to connect to the server at the IP address contained
		// within the current node
		connect_result = connect(socket_fd, itr->ai_addr, itr->ai_addrlen);
		
		if (connect_result == 0) {
			break;
		}

		// Step our iterator
		itr = itr->ai_next;
	}

	if (connect_result != 0) {
		printf("Error. Failed to connect to server.\n");
	}

	// Can now proceed to use write / read, or send / recv

	/*
	int connect_result = connect(socket_fd, (struct sockaddr*) (&server_address), sizeof(server_address));
	if (connect_result != 0) {
		printf("Error. Failed to connect to server.\n");
	}
	*/
}
