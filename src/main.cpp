#include "Server.hpp"
#include "MockCommandParser.hpp"

#include "PingCommand.hpp"

int main() {

    asio::io_context context;

    RedisCommand::ICommandParser* parser = new RedisCommand::MockCommandParser();

    RedisServer::Server server(context, 1111, parser);

    server.start();
    context.run();

    return 0;
}