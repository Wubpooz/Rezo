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
    client.sin_addr.s_addr = INADDR_ANY;
    
    server.sin_port = bind(sockfd,(struct sockaddr *)&client,size); // sin port still 0 after that
 
 
    char* msg_rec = '\0';

    while(1){
        recvfrom(sockfd,msg_rec,size,0,(struct sockaddr *)&client,&size);
        printf("%s\n",msg_rec);

        if(*msg_rec!='\0'){close(sockfd);}
    }

    return 0;
}