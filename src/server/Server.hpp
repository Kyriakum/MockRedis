#ifndef SERVER_HPP
#define SERVER_HPP

#include <asio.hpp>
#include "Logging.h"
#include "ClientSession.hpp"
#include "IParserProvider.hpp"

#define BACKLOG 5

namespace RedisServer {

    class Server {
        asio::ip::tcp::acceptor m_acceptor;
        Redis::IParserProvider* m_provider;

    public:
        Server(asio::io_context&, short, Redis::IParserProvider*);

        void async_accept_client();
        void start();
    };
}

#endif //SERVER_HPP
