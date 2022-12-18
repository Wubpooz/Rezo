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
    struct sockaddr_in client, server;
    unsigned int size = sizeof(client);

    
    if((sockfd = socket(PF_INET,SOCK_DGRAM,0))<0){ 
        perror("socket creation failed\n"); 
        exit(EXIT_FAILURE); 
    } 

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    if(bind(sockfd,(const struct sockaddr *)&server,sizeof(server))<0){ 
        perror("bind failed\n"); 
        exit(EXIT_FAILURE); 
    }

 
    char* msg_rec = malloc(size);
    int rec_len = 0;

    while(1){
        rec_len = recvfrom(sockfd,msg_rec,size,0,(struct sockaddr *)&client,&size);
        if(msg_rec!=NULL && rec_len!=-1){break; close(sockfd);}
    }
    
    msg_rec[rec_len] = '\0';
    printf("Message reçu : %s\n",msg_rec);

    return 0;
}