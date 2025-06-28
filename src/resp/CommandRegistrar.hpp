#ifndef COMMANDREGISTRAR_HPP
#define COMMANDREGISTRAR_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include "Command.hpp"

namespace RedisCommand {
    class CommandRegistrar {
        inline static std::unordered_map<std::string, Command*> s_registry;

    public:
        CommandRegistrar() = delete;
        CommandRegistrar(const CommandRegistrar&) = delete;
        CommandRegistrar& operator=(const CommandRegistrar&) = delete;

        static void register_command(std::string, Command*);

        // TODO make optional
        static Command* get_command(const std::string&);


    };
}

#endif //COMMANDREGISTRAR_HPP
