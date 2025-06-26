#ifndef SERVER_HPP
#define SERVER_HPP

#include <asio.hpp>
#include "Logging.h"

#define BACKLOG 5

namespace RedisServer {

    class Server {
        asio::ip::tcp::acceptor m_acceptor;

    public:
        Server(asio::io_context&, short);

        void async_accept_client();
        void start();
    };
}

#endif //SERVER_HPP
