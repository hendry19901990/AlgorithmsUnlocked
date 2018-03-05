#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
int main(int argc, char* argv[])
{
    int client, server;
    int port = 8083;
    bool isExit = false;
    int bufsize = 8192;
    char buffer[bufsize];
    /* -----------Standard sockaddr_in --------------------*/
    struct sockaddr_in server_addr;
    socklen_t size;
    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    /* --------------- socket() function ------------------*/
    client = socket(AF_INET, SOCK_STREAM, 0);
    if(client < 0)
    {
        cout << "\nSocket creation failed : ESOCKERR" << endl;
        exit(1);
    }
    cout << "\nSocket established" << endl;
    /* -----------From struct sockaddr_in --------------------*/
    /*------------This data is nessecary for binding----------*/
    server_addr.sin_family = AF_INET; // addr family 
    server_addr.sin_addr.s_addr = htons(INADDR_ANY); // ip
    server_addr.sin_port = htons(port); // port 
    /*--------------Binding the socket via bind()--------------*/
    if((bind(client,(struct sockaddr*)&server_addr, sizeof(server_addr))) < 0)
    {
        cout << "\nError binding connection : EADDRUSED" << endl;
        return -1;
    }
    int server_addr_size = sizeof(server_addr);
    cout << "\nServer Running. Waiting for Clients " << endl;
    /*------------------Listen Call-----listen()-------------------*/
    listen(client,4);
    int countClient = 1;
    /*--------------------Server accepts incomming connections-------*/
    server = accept(client, (struct sockaddr*)&server_addr, &size);   
    if(server > 0){
        cout << "\nError in connection" << endl;
    }
    while(server > 0)
    {
        strcpy(buffer,"Server Connected\n");
        /*------Send data----------*/
        send(server, buffer, bufsize, 0);
        cout << "\nConnected with client # " << countClient << endl;
        cout << "\nEnter & to end connection\n" << endl;
        /*------Client will send data-----*/
        cout << "\nClient data:  ";
        do{
            /*-----------------Recieve data--------------*/
            recv(server, buffer, bufsize, 0);
            cout << buffer << "  ";
            if(*buffer == '&'){
                /*-------Connection termination----------*/
                *buffer = '%';
                /*-------Server isExit---------------------*/
                isExit = true;
            }
        }while ( *buffer != '%');
        /*--------Server-side data----------------*/
        do{
            cout << "\nServer : ";
            do{
                cin >> buffer;
                send(server, buffer, bufsize, 0);
                /*------------Termination----------------*/
                if( *buffer == '&'){
                    send(server, buffer, bufsize, 0);
                    *buffer = '%';
                    isExit = true;
                }
            }while ( *buffer != '%');
            /*----------------Client-----------------*/
            cout << "\nClent : ";
            do{
                recv(server, buffer, bufsize, 0);
                cout << buffer;
                if( *buffer == '&'){
                    send(server, buffer, bufsize, 0);
                    *buffer = '%';
                    isExit = true;
                }
            }while ( *buffer != '%');
        }while (!isExit);
        /*---------------Close Connection close()-----------------*/
        cout << "\n\nConnection terminated with IP : " << inet_ntoa(server_addr.sin_addr);
        close(server);
        /*-------------Closed Server-------------------------------*/
        cout << "\nServer Closed" << endl;
        isExit = false;
        exit(1);
    }
    /*-------------------------Close Client--------------------------*/
    close(client);
    cout << "\nClient Offline" << endl;
    return 0;
}