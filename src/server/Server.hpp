#ifndef SERVER_HPP
#define SERVER_HPP

#include <asio.hpp>
#include "Logging.h"
#include "ClientSession.hpp"
#include "ICommandParser.hpp"

#define BACKLOG 5

namespace RedisServer {

    class Server {
        asio::ip::tcp::acceptor m_acceptor;
        RedisCommand::ICommandParser* m_parser;

    public:
        Server(asio::io_context&, short, RedisCommand::ICommandParser*);

        void async_accept_client();
        void start();
    };
}

#endif //SERVER_HPP
