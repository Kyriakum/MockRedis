#include "Server.hpp"
#include "IParserProvider.hpp"
#include "RespParserProvider.hpp"

#include "PingCommand.hpp"
int main() {

    try {
        asio::io_context context;

        Redis::IParserProvider* provider = new Redis::RespParserProvider();
        RedisServer::Server server(context, 1111, provider);

        server.start();
        context.run();
    } catch (const std::exception& e) {
        LOG_ERROR(e.what());
    }
    return 0;
}