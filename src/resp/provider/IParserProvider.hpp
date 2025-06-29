#ifndef IPARSERPROVIDER_HPP
#define IPARSERPROVIDER_HPP

#include "Provider.hpp"

namespace Redis {

    class IParserProvider : public Provider<RedisProtocol::IProtocolParser> {
    public:
        ~IParserProvider() override = default;
        std::unique_ptr<RedisProtocol::IProtocolParser> provide() override = 0;
    };
}

#endif //IPARSERPROVIDER_HPP
