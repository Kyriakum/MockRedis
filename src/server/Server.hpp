#ifndef SERVER_HPP
#define SERVER_HPP

#include <asio.hpp>

#define BACKLOG 5

namespace RedisServer {

    asio::ip::tcp::acceptor create_server_socket(asio::io_context&, int);
}

#endif //SERVER_HPP
