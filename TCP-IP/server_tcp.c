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

    
    if((sockfd = socket(PF_INET,SOCK_STREAM,0))<0){ 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    server.sin_family = PF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    if(bind(sockfd,(const struct sockaddr *)&server,sizeof(server))<0){ 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }
    

    if(listen(sockfd,1)==-1){ 
        perror("request not found"); 
        exit(EXIT_FAILURE); 
    }

    if((int socktb = socket(PF_INET,SOCK_SOCK_STREAM,0))<0){ 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    accept(socktb,(struct sockaddr)&client,&sizeof(client));    //INITALIZE CLIENT


    char* msg_rec = malloc(20);
    int rec_len = 0;

    while(1){
        rec_len = recvfrom(sockfd,msg_rec,size,0,(struct sockaddr *)&client,&size);
        if(msg_rec!=NULL && rec_len!=-1){break; close(sockfd);}
    }
    
    msg_rec[rec_len] = '\0';
    printf("Message : %s\n",msg_rec);

    close();

    return 0;
}