#ifndef CLIENTSESSION_HPP
#define CLIENTSESSION_HPP

#include <memory>
#include <asio.hpp>
#include <IProtocolParser.hpp>

#include "Logging.h"
#include "IParserProvider.hpp"
#include "RedisCommandParser.hpp"

namespace RedisServer {
	class ClientSession : public std::enable_shared_from_this<ClientSession> {
    	asio::ip::tcp::socket m_socket;
    	asio::streambuf m_buffer;
        Redis::IParserProvider* m_provider;
		std::optional<std::unique_ptr<RedisProtocol::IProtocolParser>> m_parser = std::nullopt;

		void read();

	    std::string create_response(const std::vector<std::string> &command_args);
		void send_response(const std::string& response);

    public:
        explicit ClientSession(asio::ip::tcp::socket&&, Redis::IParserProvider*);

		void start();
	};
}

#endif //CLIENTSESSION_HPP
