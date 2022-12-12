#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 9600


int main(int argc, char*argv[]){

    int sockfd;
    struct sockaddr_in client;
    struct sockaddr_in server;
    unsigned int size;
    
    
    sockfd = socket(PF_INET, SOCK_DGRAM,0);
    
    client.sin_family = AF_INET;
    client.sin_port = PORT;
    unsigned int ip = 192168001001; //problème conv car long int
    struct in_addr IP_client = {ip};    // IP = 192.168.1.1
    client.sin_addr = IP_client;
    
    
    server.sin_port=bind(sockfd,&server,size);
    
    
    char* msg_rec;
    char* msg_sent;

    while(1){
        recvfrom(sockfd,msg_rec,size,0,&server,8);  // the 8 are placeholders and should be type const struct sockaddr * et pas sockaddr_in
        write(sockfd,msg_sent,8); 
    }
    //close();

    return 0;
}
