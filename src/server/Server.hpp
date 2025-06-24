#ifndef SERVER_HPP
#define SERVER_HPP

#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>

#define BACKLOG 5

namespace RedisServer {

    int create_server_socket(int);
}

#endif //SERVER_HPP
