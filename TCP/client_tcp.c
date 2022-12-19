#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#include <arpa/inet.h>
#include <errno.h>
#include <limits.h>

#define SIZE 100
#define PORT 9600


int main(int argc, char* argv[]){

    int sockfd;
    struct sockaddr_in server;
    struct hostent *host;
    char buff[SIZE];
    unsigned int len = 20;


    if((sockfd = socket(PF_INET,SOCK_DGRAM,0))<0){ 
        perror("Socket creation failed."); 
        exit(EXIT_FAILURE); 
    }
    printf("Socket created.\n");

    if(argc<2){return 1;}
    host = gethostbyname(argv[1]);
    if(!host) return 1;
    char* IP = inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);

    server.sin_family = host->h_addrtype;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(IP);

    
    if(connect(sockfd,(struct sockaddr *)&server,sizeof(server))!=0){
        printf("Connection failed.");
        exit(EXIT_FAILURE); 
    }
    printf("Connection successful.\n");

    printf("Client Message : ");
    fgets(buff,len,stdin);
    write(sockfd,buff,len);
    printf("Message sent.\n");

    close(sockfd);
    return 0;
}