#include "socketutil.h"
#include <stdbool.h>
#include "pthread.h"


struct AcceptedSocket{
    int acceptedSocketFD;
    struct sockaddr_in address;
    int error;
    bool acceptedSuccessfully;

};

struct AcceptedSocket acceptedSocketArr[10];
int countForAccepted = 0;


///****************** Function Declaration *******//////////
struct AcceptedSocket * acceptIncomingConnection(int serverSocketFD);

void * receivedAndPrintIncomingData(void * socketFD);

void acceptNewConnectionReceivePrint(int serverSocketFD);
void startAcceptingIncomingConnections(int serverSocketFD);
void receivePrintDataOnDifThreads(struct AcceptedSocket * pSocket);

void sendReceiveMessageToClient(char * buffer, int socketFD);
//////************************ENDS****************//// *

int main(){

    int serverSocketFD = createTCPIpv4Socket();
    struct sockaddr_in *serverAddress = createIPv4Address("", 2000);

    int result = bind(serverSocketFD, (struct sockaddr*)serverAddress, sizeof(*serverAddress));

    if (result == 0){
        printf("Socket was bound successfully %d\n", result);

    }else {
        printf("Failed to Bind %d", result);
    }

    int listenResult = listen(serverSocketFD, 10);  ///queue up 

    // if (clientSocket== 0){
    //     printf("Successfully Received client socket");
    // }
    startAcceptingIncomingConnections(serverSocketFD);
    
    shutdown(serverSocketFD, SHUT_RDWR);

    return 0;
    

}


///************************ Function Definition *******//////////

void startAcceptingIncomingConnections(int serverSocketFD){

    while(true){
        struct AcceptedSocket * clientSocket = acceptIncomingConnection(serverSocketFD);

        acceptedSocketArr[countForAccepted++] = *clientSocket;

        receivePrintDataOnDifThreads(clientSocket);
       
    }
    // pthread_t id;
    // pthread_create(&id, NULL, acceptNewConnectionReceivePrint,serverSocketFD );

}



void receivePrintDataOnDifThreads(struct AcceptedSocket * pSocket){

    pthread_t id;
    pthread_create(&id, NULL, &receivedAndPrintIncomingData, (void *)pSocket);
}



void * receivedAndPrintIncomingData(void * socketFD){

    struct AcceptedSocket * socFD  = (struct AcceptedSocket *) socketFD;

    char buffer[1024];

    while(true){

        ssize_t bytes_received = recv(socFD->acceptedSocketFD, buffer, sizeof(buffer) - 1, 0); 


        if(bytes_received > 0){
            buffer[bytes_received] = '\0';
            printf("Response: \n%s\n", buffer );

            sendReceiveMessageToClient(buffer, socFD->acceptedSocketFD);
          

        }

        if (bytes_received == 0)
            break;
    }

    free(socFD);
    close(socFD->acceptedSocketFD);
    
}

void sendReceiveMessageToClient(char * buffer, int socketFD){
    
    for (int i = 0; i<countForAccepted; i++){
        if(acceptedSocketArr[i].acceptedSocketFD != socketFD){
           ssize_t sent =  send(acceptedSocketArr[i].acceptedSocketFD, buffer, strlen(buffer), 0);

            if(sent < 0 ){
                printf("error sending data");
            }
            else if (sent ==0){
                printf("Heeuay == 0");
            }
            else{
                printf("No error sending data");
            }
        }
    }

}

struct AcceptedSocket * acceptIncomingConnection(int serverSocketFD){
    struct sockaddr_in clientAddress;
    int clientAddrSize = sizeof(struct sockaddr_in);
    int clientSocFD= accept(serverSocketFD, (struct sockaddr*)&clientAddress, &clientAddrSize);

    struct AcceptedSocket * acceptedSocket = malloc(sizeof(struct AcceptedSocket));

    acceptedSocket->address = clientAddress;
    acceptedSocket->acceptedSocketFD = clientSocFD;
    acceptedSocket->acceptedSuccessfully = clientSocFD >0;

    if(!acceptedSocket->acceptedSuccessfully);
        acceptedSocket->error = clientSocFD;


    return acceptedSocket;
}
