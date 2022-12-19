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


int main(int argc, char* argv[]){

    int sockfd;
    struct sockaddr_in client, server;
    unsigned int size;    
    char buff[SIZE];
    unsigned int len = 20;

    
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
        perror("Bind failed.\n"); 
        exit(EXIT_FAILURE); 
    }
    printf("Binding successful.\n");
    

    if ((listen(sockfd, 1)) != 0) {
		printf("Listen failed.\n");
		exit(0);
	}
	printf("Listening...\n");

    size = sizeof(client);
    int msgfd = accept(sockfd, (struct sockaddr *)&client, &size);
    if(msgfd<0){ 
        perror("Connection socket creation failed.\n"); 
        exit(EXIT_FAILURE); 
    }
    printf("Request accepted.\n");


    while(1){
        read(msgfd, buff, sizeof(buff));
        printf("Client : %s", buff);
        
        printf("Server : ");
        fgets(buff,len,stdin);
        write(msgfd,buff,len);
        //printf("Message sent.\n");

        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Exit.\n");
            break;
        }
    }

    close(msgfd);
    close(sockfd);
    return 0;
}