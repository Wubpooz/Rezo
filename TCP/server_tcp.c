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
        perror("Socket creation failed."); 
        exit(EXIT_FAILURE); 
    } 

    server.sin_family = PF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    client.sin_family = PF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = htons(PORT);
    
    if(bind(sockfd,(const struct sockaddr *)&server,sizeof(server))<0){ 
        perror("Bind failed."); 
        exit(EXIT_FAILURE); 
    }
    printf("Binding successful.\n");
    

    printf("Listening...\n");
    if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed.\n");
		exit(0);
	}
    printf("Heard.\n");
    int socktb;
    if((socktb = accept(sockfd,(struct sockaddr *)&client,&size))<0){ 
        perror("Connection socket creation failed."); 
        exit(EXIT_FAILURE); 
    }
    printf("Request accepted.\n");

    char* msg_rec = malloc(20);
    int rec_len = 0;

    printf("Waiting for message...\n");
    while(1){
        rec_len = read(socktb,msg_rec,20);
        if(msg_rec!=NULL && rec_len>0){break; close(socktb);}
    }
    
    msg_rec[rec_len] = '\0';
    printf("Message : %s\n",msg_rec);

    close(sockfd);
    return 0;
}