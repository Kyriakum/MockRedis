#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>
#include <string>
#include "Logging.h"

namespace RedisCommand {
    class Command {
        public:
            virtual ~Command() = default;
            virtual void execute() = 0;

    };

}
#endif //COMMAND_HPP
