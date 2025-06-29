#include "CommandRegistrar.hpp"

void RedisCommand::CommandRegistrar::register_command(std::string str, Command* instance) {
    RedisCommand::CommandRegistrar::get_registry().emplace(std::move(str), instance);
}

RedisCommand::Command* RedisCommand::CommandRegistrar::get_command(const std::string& str) {
    const auto& registry = RedisCommand::CommandRegistrar::get_registry();
    if(auto it = registry.find(str); it != registry.end()) {
        return it->second;
    }
    return nullptr;
};

std::unordered_map<std::string, RedisCommand::Command*>& RedisCommand::CommandRegistrar::get_registry() {
    static std::unordered_map<std::string, RedisCommand::Command*> registry;
    return registry;
}
