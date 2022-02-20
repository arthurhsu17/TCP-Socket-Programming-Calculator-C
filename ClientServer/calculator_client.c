#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h> 
#include <unistd.h>
#include<string.h> 
#include<strings.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char* argv[])
{

    int b,sockfd,sin_size,con,n,len, portnum;
    float num1,num2,ans;
    int choice;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buff[256];

    if(argc < 3)
    {
        fprintf(stderr,"Usage %s hostname port\n", argv[0]);
        exit(0);
    }
    
    portnum= atoi(argv[2]);
    sockfd= socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        error("ERROR opening socket");
    }

    server= gethostbyname(argv[1]);
    if(server == NULL)
    {
        fprintf(stderr, "Host does not exist");
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    bcopy((char *) server-> h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port=htons(portnum);

    if(connect(sockfd,(struct sockaddr *) &servaddr, sizeof(servaddr))<0)
    {
     error("Connection failed");
    }



    S: bzero(buff,256);
    n= read(sockfd,buff,255);
    if(n<0)
        {
        error("Error reading socket 1");
        }
        printf("Server -  %s\n",buff);
        scanf("%f",&num1);
        write(sockfd, &num1, sizeof(int));
        bzero(buff,256);
        n= read(sockfd,buff,255);

    if(n<0)
        {
        error("Error reading socket 2");
        }
        printf("Server -  %s\n",buff);
        scanf("%f",&num2);
        write(sockfd, &num2, sizeof(int));

        bzero(buff,256);
        n= read(sockfd,buff,255);

    if(n<0)
    {
        error("Error reading socket 3");
    }
        printf("Server -  %s\n",buff);
        scanf("%d",&choice);
        write(sockfd, &choice, sizeof(int));

        if(choice ==5)
        {
        goto Q;
        }

        read(sockfd, &ans, sizeof(int));
        printf("Server - The answer is : %f\n", ans);

        if(choice !=5)
        {
            goto S;
        }

    Q:  
        printf("You have selected to exit. Exit done");
        close(sockfd);;

        return 0;
}
