#include "ClientSession.hpp"

RedisServer::ClientSession::ClientSession(asio::ip::tcp::socket&& socket) : m_socket(std::move(socket)) {}

void RedisServer::ClientSession::start() {
    auto self = shared_from_this();

    asio::async_read_until(m_socket, m_buffer, "\r\n", [self](const std::error_code& ec, std::size_t bytes_transferred) {
    if(!ec){
        std::istream input(&self->m_buffer);
        std::string line;
        std::getline(input, line);
	    LOG_INFO("Received line: {}", line);
        self->send_response();
    } else {
        LOG_INFO("ClientSession read error occured: {}", ec.message());
    }
  });
}

void RedisServer::ClientSession::parse_header() {}

void RedisServer::ClientSession::parse_body() {}

void RedisServer::ClientSession::send_response() {
    auto self = shared_from_this();

    const std::string response = "+PONG!\r\n";
    auto buffer = asio::buffer(response);

    asio::async_write(m_socket, buffer, [self](const std::error_code& ec, std::size_t bytes_transferred) {
    if(!ec) {
    	self->start();
    }
    else {
        LOG_INFO("ClientSession write error occured: {}", ec.message());
    }
  });
}
