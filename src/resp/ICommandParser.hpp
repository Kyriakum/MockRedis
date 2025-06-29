#ifndef ICOMMANDPARSER_HPP
#define ICOMMANDPARSER_HPP

#include <string>

namespace RedisCommand {
    class ICommandParser {
    public:
        virtual ~ICommandParser() = default;
        virtual std::string parse_command(const std::string& command) = 0;
    };
}
#endif //ICOMMANDPARSER_HPP
