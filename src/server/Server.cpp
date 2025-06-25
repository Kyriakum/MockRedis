#include "Server.hpp"

asio::ip::tcp::acceptor RedisServer::create_server_socket(asio::io_context& context, int port) {
    asio::ip::tcp::acceptor acceptor(context);
    asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), port);

    acceptor.open(endpoint.protocol());
    acceptor.set_option(asio::ip::tcp::acceptor::reuse_address(true));
    acceptor.bind(endpoint);
    acceptor.listen(BACKLOG);

    return acceptor;
}
