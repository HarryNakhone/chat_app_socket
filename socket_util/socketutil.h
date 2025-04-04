#ifndef SOCKET_UTIL_SOCKETUTIL_H
#define SOCKET_UTIL_SOCKETUTIL_H

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct sockaddr_in * createIPv4Address(char *ip, int port);

int createTCPIpv4Socket();

#endif // SOCKET_UTIL_SOCKETUTIL_H