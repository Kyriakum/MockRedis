#include "CommandRegistrar.hpp"

void RedisCommand::CommandRegistrar::register_command(std::string str, Command* instance) {
    RedisCommand::CommandRegistrar::s_registry.emplace(std::move(str), instance);
}

RedisCommand::Command* RedisCommand::CommandRegistrar::get_command(const std::string& str) {
    if(auto it = s_registry.find(str); it != s_registry.end()) {
        return it->second;
    }
    return nullptr;
};

