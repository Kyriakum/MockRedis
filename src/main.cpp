#include <iostream>
#include "Server.hpp"

int main() {

    asio::io_context context;

    RedisServer::Server server(context, 1111);

    server.start();
    context.run();

    return 0;
}