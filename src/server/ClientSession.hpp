#ifndef CLIENTSESSION_HPP
#define CLIENTSESSION_HPP

#include <memory>
#include <asio.hpp>
#include "Logging.h"
#include "ICommandParser.hpp"

namespace RedisServer {
	class ClientSession : public std::enable_shared_from_this<ClientSession> {
    	asio::ip::tcp::socket m_socket;
    	asio::streambuf m_buffer;
		RedisCommand::ICommandParser* m_parser;

    public:

        explicit ClientSession(asio::ip::tcp::socket&& socket, RedisCommand::ICommandParser*);
		void start();
        void parse_header();
   		void parse_body();
        void send_response();
	};
}

#endif //CLIENTSESSION_HPP
