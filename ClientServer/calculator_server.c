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
    exit(1);
}


int main(int argc, char *argv[])
{

    if(argc<2)
    {
        fprintf(stderr,"Port No. not provided. Program exiting\n");
        exit(1);
    }

    int sockfd,n, portnum, newsockfd;
    char buff[255];
    float num1,num2,ans;
    int choice;
    struct sockaddr_in servaddr, cli_addr;
    socklen_t clilen;

    sockfd= socket(AF_INET, SOCK_STREAM,0);
    if(sockfd<0)
    {
        error("Error opening socket.");
    }

    bzero((char*) &servaddr, sizeof(servaddr));
    portnum= atoi(argv[1]);
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr= INADDR_ANY;
    servaddr.sin_port=htons(portnum);

    if(bind(sockfd,(struct sockaddr *) &servaddr, sizeof(servaddr))<0)
    {
        error("Connection failed hello");
    }

    listen(sockfd,5);
    clilen= sizeof(cli_addr);
    newsockfd= accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);

    if(newsockfd <0)
    {
        printf("Error on Accept");
    }

    S: n= write(newsockfd, "Enter first number: ",strlen("Enter first number"));

    if(n<0 ) printf("ERROR writing to socket");
    {
        read(newsockfd, &num1, sizeof(int));
        printf("Client - Number 1 is %f\n", num1);
    }
    n= write(newsockfd, "Enter second number: ",strlen("Enter second number"));

    if(n<0) error("ERROR writing to socket");
    {
        read(newsockfd, &num2, sizeof(int));
        printf("Client - Number 2 is %f\n", num2);
    }
    n= write(newsockfd, "Enter your choice of arithmetic: \n1.Addition\n2.Subtraction\n3.Multiplication\n4.Divsion\n5.Exit\n", strlen("Enter your choice of arithmetic: \n1.Addition\n2.Subtraction\n3.Multiplication\n4.Divsion\n5.Exit\n"));

    if(n<0) error("ERROR writing to socket");
    {
        read(newsockfd, &choice, sizeof(int));
        printf("Client - Choice is %d\n", choice);
    }
        
        switch(choice)
        {
            case 1:
            ans= num1 +num2;
            break;
            
            case 2:
            ans= num1 -num2;
            break;

            case 3:
            ans= num1 *num2;
            break;

            case 4:
            ans= num1 /num2;
            break;

            case 5:
            goto Q;
            break;
        }

        write(newsockfd, &ans, sizeof(int));
        if(choice !=5)
        {
            goto S;
        }

        Q:  close(newsockfd);
            close(sockfd);

        return 0;

}

