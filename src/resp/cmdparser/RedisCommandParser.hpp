#ifndef REDISCOMMANDPARSER_HPP
#define REDISCOMMANDPARSER_HPP

#include "ICommandParser.hpp"
#include "CommandRegistrar.hpp"
#include <locale>

namespace RedisCommand {
	class RedisCommandParser final : public ICommandParser, public Singleton<RedisCommandParser> {
        public:
		std::string parse_command(const std::vector<std::string> &command) override;
	};
}

#endif //REDISCOMMANDPARSER_HPP
