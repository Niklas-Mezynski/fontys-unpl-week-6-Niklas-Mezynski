// Client side C/C++ program to demonstrate Socket programming 
// See: https://www.geeksforgeeks.org/socket-programming-cc/

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h> 

#define PORT 8080 

int main(int argc, char const *argv[]) { 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	char *hello = "Hello from client"; 
	char *hello1 = "Hello from client - 1"; 
	char *hello2 = "Hello from client - 2"; 
	char *hello3 = "Hello from client - 3"; 
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	// memset(&serv_addr, '0', sizeof(serv_addr));
	unsigned char* p = &serv_addr;
	for (int i = 0; i < sizeof(serv_addr); i++)
	{
		*p = '0';
		p++;	
	}

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT);
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) { 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 
	send(sock , hello , strlen(hello) , 0 ); 
	sleep(2);
	send(sock , hello1 , strlen(hello1) , 0 ); 
	sleep(2);
	send(sock , hello2 , strlen(hello2) , 0 ); 
	sleep(2);
	send(sock , hello3 , strlen(hello3) , 0 );
	sleep(2);
	printf("Hello messages sent by Client\n"); 
	valread = read( sock , buffer, 1024); 
	printf("Client received: %s\n",buffer ); 
	return 0; 
} 

