#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>
#include "Logging.h"

namespace RedisCommand {
    class Command {
        public:
            virtual ~Command() = default;
            virtual std::string execute(const std::vector<std::string>&) = 0;

    };

}
#endif //COMMAND_HPP
