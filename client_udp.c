#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>


#include <errno.h>
#include <limits.h>

#define SIZE 100
#define PORT 9600

#define STR2(x) #x
#define STR(X) STR2(X)


int main(int argc, char* argv[]){

    int sockfd;
    struct sockaddr_in server;
    struct sockaddr_in client;

    struct hostent host;
    char buff[SIZE];
    unsigned int len = 20;  //what's that ?


    sockfd = socket(PF_INET,SOCK_DGRAM,0);

    if(argc<2){return 1;}
    host = *gethostbyname(argv[1]);

    struct in_addr IP = {(unsigned long)host.h_addr_list[0][0]};

    server.sin_family = host.h_addrtype;
    server.sin_port = PORT;
    server.sin_addr.s_addr = INADDR_ANY; // or INADDR_ANY ?

    client.sin_port = PORT;

    printf("Client message : ");
    scanf("%" STR(len) "s",buff); // limit input size to len

    sendto(sockfd,buff,SIZE,0,(const struct sockaddr *) &server,sizeof(server));
    printf("Message sent.\n");

    return 0;
}