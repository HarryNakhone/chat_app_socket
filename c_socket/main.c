#include"socketutil.h"
#include <stdbool.h>
#include "pthread.h"
void startThreadsForListening(int socketFD);
void * listeningAndPrint(void * socketFD);
void readConsoleEntriesAndSendToServer(int socketFD);

int main(){

    int socketFD = createTCPIpv4Socket();
    struct sockaddr_in *address = createIPv4Address("127.0.0.1", 2000);

    int result = connect(socketFD, (struct sockaddr *)address, sizeof (*address) );

    if(result == 0)
        printf("connection was successful kuay humyai\n");



    startThreadsForListening(socketFD);

    readConsoleEntriesAndSendToServer(socketFD);
  


    close(socketFD);
    
    return 0;
}

void readConsoleEntriesAndSendToServer(int socketFD){

    char * name = NULL;
    size_t nameSize = 0;

    printf("please enter your name: \n");
    ssize_t nameCount = getline(&name, &nameSize, stdin);
    name[nameCount-1] = '\0';



    char * buffe = NULL;
    size_t lineSize = 0;

    printf("Type yo message or Type exit to exit>>>\n");

    char buffer[1024];

    while(true){
        ssize_t charCount = getline(&buffe, &lineSize, stdin);
        buffe[charCount-1]= '\0';

        sprintf(buffer,"%s:%s",name,buffe);


        if (charCount > 0){
            if(strcmp(buffer, "exit\n") ==0)
                break;


            
            ssize_t amountSent = send(socketFD, buffer, strlen(buffer), 0);
        }


    }

}

void startThreadsForListening(int socketFD){

    pthread_t id;
    int * socketFDPtr = malloc(sizeof(int));
    *socketFDPtr = socketFD;
    pthread_create(&id, NULL, &listeningAndPrint, (void *)socketFDPtr);

  
}


void * listeningAndPrint(void * socketFD){
    int * socFD  = (int *) socketFD;

    char buffer[1024];

    while(true){

        ssize_t bytes_received = recv(*socFD, buffer, sizeof(buffer) - 1, 0); 



        if(bytes_received > 0){
            buffer[bytes_received] = '\0';
            printf("Response is: %s\n", buffer );

        }

        if (bytes_received == 0)
            break;
    }

    free(socketFD);

    close(*socFD);
    
}
