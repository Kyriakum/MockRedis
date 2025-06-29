#include "RedisCommandParser.hpp"

std::string RedisCommand::RedisCommandParser::parse_command(const std::vector<std::string> &command) {
    if(command.empty()) { return "-ERR\r\n"; }
    std::string cmd = command[0];

    // TODO move to a String Formatter specific class (SRP)

    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);
    cmd.erase(std::remove(cmd.begin(), cmd.end(), '\r'), cmd.end());

    auto command_class = RedisCommand::CommandRegistrar::get_command(cmd);
    if (command_class.has_value()) {
        return command_class.value()->execute(command);
    }
    return "-ERR\r\n";
}