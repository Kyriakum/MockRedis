#include <iostream>
#include "Server.hpp"

int main() {

    int server_fd = RedisServer::create_server_socket(1111);
    if (server_fd < 0) {
        std::cerr << "Failed to create server socket" << std::endl;
        return -1;
    }
    std::cout << "Server initiated! File descriptor: " << server_fd << std::endl;
    return 0;
}