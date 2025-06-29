#include "Server.hpp"

RedisServer::Server::Server(asio::io_context& context, short port, RedisCommand::ICommandParser* parser) : m_acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), m_parser(parser) {
    m_acceptor.listen(BACKLOG);
}

void RedisServer::Server::start() {
    async_accept_client();
}

void RedisServer::Server::async_accept_client() {

    LOG_INFO("Starting async_accept_client!");

    m_acceptor.async_accept([this](const asio::error_code ec, asio::ip::tcp::socket sock) {
        if (!ec) {
            const auto session = std::make_shared<ClientSession>(std::move(sock), m_parser);
            session->start();
        } else {
            LOG_INFO("Error occured: {}", ec.message());
        }
        async_accept_client();
    });

    LOG_INFO("Server accepts clients!");
}
