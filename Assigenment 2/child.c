// child file
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 80
int main(int argc, char const *argv[]) 
{ 
   int new_socket, valread; 
    char buffer[1024] = {0}; 
    char *hello = "Hello from server";
    printf("Assign a socket...");
  new_socket = atoi(argv[1]);
  printf("Assigned a socket... new_socket = %d", new_socket);
  
  
setuid(65534);
    int check = getuid();
    printf("the uid is: %d", check);
    valread = read( new_socket , buffer, 1024); 
    printf("%s\n",buffer ); 
    send(new_socket , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n");
  return 0;
}
