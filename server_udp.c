#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 9600


int main(int argc, char*argv[]){

    int sockfd;
    struct sockaddr_in client;
    struct sockaddr_in server;
    unsigned int size;
    
    
    sockfd = socket(PF_INET, SOCK_DGRAM,0);
    
    client.sin_family = AF_INET;
    client.sin_port = PORT;
    struct in_addr IP_client = {192168001001};    // IP = 192.168.1.1
    client.sin_addr = IP_client;
    
    
    server.sin_port=bind(sockfd,&server,size);
    
    
    
    while(1){
        recvfrom();
        write();
    
    }
    close();

    return 0;
}
