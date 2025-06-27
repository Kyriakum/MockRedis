#include "ClientSession.hpp"

void RedisServer::ClientSession::start() {
  auto self = shared_from_this();
  asio::async_read_until(m_socket, m_buffer, "\r\n", [self](const std::error_code& ec, std::size_t bytes_transferred) {
     // TODO setup parsing sequence
  });
}
void RedisServer::ClientSession::parse_header() {}
void RedisServer::ClientSession::parse_body() {}
void RedisServer::ClientSession::send_response() {}
