#ifndef AUTOREGISTER_HPP
#define AUTOREGISTER_HPP

#include "CommandRegistrar.hpp"
#include "Command.hpp"



namespace RedisCommand {

template<class T>
    class AutoRegister {
        public:
            AutoRegister(const std::string& name) {
                RedisCommand::CommandRegistrar::register_command(name, &T::getInstance());
            }
    };
}

#define REGISTER_COMMAND(CommandType, CommandName) \
    RedisCommand::AutoRegister<CommandType> register_##CommandType(CommandName);
#endif //AUTOREGISTER_HPP
