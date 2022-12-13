#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define SIZE 100
#define PORT 9600

#define STR2(x) #x
#define STR(X) STR2(X)

int main(int argc, char* argv[]){

    int sockfd;
    struct sockaddr_in server;
    struct sockaddr_in client;

    struct hostent host;
    char* buff = (char *) malloc(SIZE);
    unsigned int len = 20;


    sockfd = socket(PF_INET,SOCK_DGRAM,0);

    struct in_addr IP = {atoi(argc>=1 ? argv[0] : 0)};   //atoi convert string to int, SUCKS

    server.sin_family = AF_INET;
    server.sin_port = PORT;
    server.sin_addr = IP;

    client.sin_port = bind(sockfd,&client,len); // connecte ????

    scanf("%" STR(len) "s",buff); // limit input size to len
    
    write(sockfd,buff,len);

    return 0;
}
