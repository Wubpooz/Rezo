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
    char* buff = (char *) malloc(SIZE);
    unsigned int len = 20;


    sockfd = socket(PF_INET,SOCK_DGRAM,0);


    // char *p;
    // int ip;
    // errno = 0;
    // long conv = strtol(argc>=2 ? argv[1] : "", &p, 10);
    // if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {} 
    // else {ip = conv; }
    if(argc<2 || argv[1]=="/"){return 1;}
    host = *gethostbyname(argv[1]);

    struct in_addr IP = {(unsigned long)**host.h_addr_list};

    server.sin_family = host.h_addrtype;
    server.sin_port = PORT;
    server.sin_addr = IP;

    client.sin_port = bind(sockfd,(struct sockaddr *)&server,host.h_length);   // previously &client et len


    scanf("%" STR(len) "s",buff); // limit input size to len
    printf("%s\n",buff);

    write(sockfd,buff,len);

    free(buff);
    return 0;
}
