#ifndef ICOMMANDPARSER_HPP
#define ICOMMANDPARSER_HPP

#include <Singleton.hpp>
#include <string>
#include <vector>

namespace RedisCommand {
    class ICommandParser {
    public:
        virtual ~ICommandParser() = default;
        virtual std::string parse_command(const std::vector<std::string> &) = 0;
    };
}
#endif //ICOMMANDPARSER_HPP
