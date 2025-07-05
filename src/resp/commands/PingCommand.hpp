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
            std::string execute(const std::vector<std::string>& args) override {
                // TODO fix loop
                // TODO figure multi arg message
                // TODO move string building to a formatter
                LOG_INFO("Called PingCommand");
                if (args.size() > 1) {
                    std::stringstream ss;
                    ss << "+";
                    auto iterator = args.begin();
                    for (iterator; args.end() > iterator; ++iterator ) {
                        if (iterator == args.begin()) { continue; }
                        ss << *iterator << " ";
                    }
                    ss << "\r\n";
                    auto str = ss.str();
                    return ss.str();
                }
                return "+hello world\r\n";
            }
    };

REGISTER_COMMAND(PingCommand, "PING");
}
#endif //PINGCOMMAND_HPP
