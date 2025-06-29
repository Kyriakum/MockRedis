#include "ClientSession.hpp"

RedisServer::ClientSession::ClientSession(asio::ip::tcp::socket&& socket, Redis::IParserProvider* provider) : m_socket(std::move(socket)), m_provider(provider) {}

void RedisServer::ClientSession::start() {
    read();
}
void RedisServer::ClientSession::read() {
    auto self = shared_from_this();

    async_read_until(m_socket, m_buffer, "\r\n", [self](const std::error_code& ec, std::size_t bytes_transferred) {
    if(!ec){
        std::istream input(&self->m_buffer);
        std::string line;
        std::getline(input, line);

        LOG_INFO("Received line: {}", line);

        if (!self->m_parser.has_value()) {
            self->m_parser = std::make_optional(self->m_provider->provide());
        }

        const auto parser = self->m_parser->get();
        parser->parse_data(line);
        self->read();

        if (parser->is_parsed()) {
            self->send_response(self->create_response(parser->get_command_args()));
        }
    } else {
        LOG_INFO("ClientSession read error occured: {}", ec.message());
    }
  });
}

std::string RedisServer::ClientSession::create_response(const std::vector<std::string> &command_args) {
    return RedisCommand::RedisCommandParser::get_instance().parse_command(command_args);
}

void RedisServer::ClientSession::send_response(const std::string& response) {
    auto self = shared_from_this();

    const auto buffer = asio::buffer(response);

    async_write(m_socket, buffer, [self](const std::error_code& ec, std::size_t) {
    if(!ec) {
        self->m_parser = std::nullopt;
    	self->read();
    }
    else {
        LOG_INFO("ClientSession write error occured: {}", ec.message());
    }
  });
}
