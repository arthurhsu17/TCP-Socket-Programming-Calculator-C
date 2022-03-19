# TCP-Socket-Programming-Calculator-C
2 number calculator using client and server connection made using C. Simple arithmetic can be done such as addition, subtraction, multiplication and division. 
The gist is that there are two programs made, one being the receiver and one being the sender. Once a connection has been made to the correct specified port, the server(receiver) will prompt the client(sender) to send the first number, and subsequently the second number, then after will ask for the choice of arithmetic of what the user wants. Attatched are screenshots of what the program does.

## Server
To run the server, you have to specify the port that it will run on, in this case I have chosen port' 12007'. Realistically it can be any number above 1023 to 65535, (1024 to 65535) as ports 0 to 1023 are reserved for privileged services and are designated as well-known ports.

`./server 12007`

<img width="561" alt="Screenshot 2022-02-20 at 2 47 34 PM" src="https://user-images.githubusercontent.com/71420919/154848394-c1854834-a0b3-4ce6-8707-e5232fb276c7.png">

As seen above, a connection is established and the server awaits for user import in the client side. 

## Client
To run the client, you have to specify the port to connect to, which in this case is port 12007, and because I am running the client from my localhost, it is from the IP address 127.0.0.1

`./client 127.0.0.1 12007`


<img width="563" alt="Screenshot 2022-02-20 at 2 47 54 PM" src="https://user-images.githubusercontent.com/71420919/154848395-eca8d532-8bff-4f33-98ec-b256d79a25f6.png">


<img width="567" alt="Screenshot 2022-02-20 at 2 48 05 PM" src="https://user-images.githubusercontent.com/71420919/154848396-a9835740-736a-4ab1-9b3d-4a0dd019add1.png">



