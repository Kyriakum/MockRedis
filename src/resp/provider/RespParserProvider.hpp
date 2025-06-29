#ifndef RESPPARSERPROVIDER_HPP
#define RESPPARSERPROVIDER_HPP

#include "RespParser.hpp"
#include <memory>
namespace Redis {
    class RespParserProvider final : public IParserProvider {
        std::unique_ptr<RedisProtocol::IProtocolParser> provide() override { return std::make_unique<RedisProtocol::RespParser>(); };
    };
}

#endif //RESPPARSERPROVIDER_HPP
