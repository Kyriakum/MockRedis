#include "Server.hpp"

RedisServer::Server::Server(asio::io_context& context, short port) : _acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)) {
    _acceptor.listen(BACKLOG);
}

void RedisServer::Server::start() {
    async_accept_client();
}

void RedisServer::Server::async_accept_client() {

    LOG_INFO("Starting async_accept_client!");

    _acceptor.async_accept([this](const asio::error_code ec, asio::ip::tcp::socket sock) {
        if (!ec) {
            // TODO create client sessions and handler for them
        } else {
            // Handle error
        }
        async_accept_client();
    });

    LOG_INFO("Server accepts clients!");
}
