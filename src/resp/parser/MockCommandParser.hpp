#ifndef MOCKCOMMANDPARSER_HPP
#define MOCKCOMMANDPARSER_HPP

#include "ICommandParser.hpp"
#include "CommandRegistrar.hpp"

namespace RedisCommand {
    class MockCommandParser final : public ICommandParser {
        std::string parse_command(const std::string& command) override {
            const auto ping_command = RedisCommand::CommandRegistrar::get_command("PING");
            if(ping_command == nullptr) {
              return "-ERR\r\n";
            }
            ping_command->execute();
            return "+PONG\r\n";
        }
    };
}

#endif //MOCKCOMMANDPARSER_HPP
