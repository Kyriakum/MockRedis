#ifndef PINGCOMMAND_HPP
#define PINGCOMMAND_HPP

#include "Command.hpp"
#include "Singleton.hpp"
#include "AutoRegister.hpp"

namespace RedisCommand {
    class PingCommand final : public Command, public Singleton<PingCommand> {
        friend class Singleton;
        PingCommand() : Command(), Singleton() {};

        public:
            std::string execute(const std::vector<std::string>&) override {
                LOG_INFO("Called PingCommand");
                return "+PONG\r\n";
            }
    };

REGISTER_COMMAND(PingCommand, "PING");
}
#endif //PINGCOMMAND_HPP
