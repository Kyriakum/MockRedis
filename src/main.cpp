#include <iostream>
#include "Server.hpp"

int main() {

    asio::io_context context;

    auto acceptor = RedisServer::create_server_socket(context, 1111);
    std::cout << "Server initiated! File descriptor: " << acceptor.native_handle() << std::endl;

    return 0;
}