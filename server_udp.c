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
    unsigned int size = 20;    // right value ?    supposed to be client address size

    
    sockfd = socket(PF_INET, SOCK_DGRAM,0);

    client.sin_family = AF_INET;
    client.sin_port = PORT;
    client.sin_addr.s_addr = INADDR_ANY;
    
    bind(sockfd,(struct sockaddr *)&server,sizeof(server)); // sin port still 0 after that
 
    // if (bind(sockfd,(struct sockaddr *)&server,sizeof(server)) == 0) {
    //     fprintf(stdout,"bind completed\n");
    // }
    // else {
    //     perror("Could not bind to socket");
    //     close(sockfd);
    //     exit(1);
    // }
 
    char* msg_rec = '\0';

    while(1){
        recvfrom(sockfd,msg_rec,size,0,(struct sockaddr *)&client,&size);

        if(*msg_rec!='\0'){break; close(sockfd);}
    }
    
    printf("Message reçu : %s\n",msg_rec);

    return 0;
}