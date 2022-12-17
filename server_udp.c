#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 9600


int main(int argc, char* argv[]){

    int sockfd;
    struct sockaddr_in client;
    struct sockaddr_in server;
    unsigned int size = 100;    // right value ?    supposed to be client address size
    
    
    sockfd = socket(PF_INET, SOCK_DGRAM,0);
    
    client.sin_family = AF_INET;
    client.sin_port = PORT;
    // unsigned long ip = 192168001001;
    // struct in_addr IP_client = {ip};   // IP = 192.168.1.1 hopefully
    // client.sin_addr = IP_client;
    client.sin_addr.s_addr = INADDR_ANY;
    
    
    server.sin_port= bind(sockfd,(struct sockaddr *)&client,size);
    printf("%d",server.sin_port);
    
    char* msg_rec = "";

    while(1){
        recvfrom(sockfd,msg_rec,size,0,(struct sockaddr *)&client,(socklen_t*)&size);
        printf("%s\n",msg_rec);
    }

    return 0;
}
