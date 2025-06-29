#include "CommandRegistrar.hpp"

void RedisCommand::CommandRegistrar::register_command(std::string str, Command* instance) {
    RedisCommand::CommandRegistrar::get_registry().emplace(std::move(str), instance);
}

std::optional<RedisCommand::Command*> RedisCommand::CommandRegistrar::get_command(const std::string& str) {
    const auto& registry = RedisCommand::CommandRegistrar::get_registry();
    if(const auto it = registry.find(str); it != registry.end()) {
        return std::make_optional(it->second);
    }
    return std::nullopt;
};

std::unordered_map<std::string, RedisCommand::Command*>& RedisCommand::CommandRegistrar::get_registry() {
    static std::unordered_map<std::string, RedisCommand::Command*> registry;
    return registry;
}
