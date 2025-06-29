#ifndef IPROTOCOLPARSER_HPP
#define IPROTOCOLPARSER_HPP
#include <string>
#include <vector>

namespace RedisProtocol {
    class IProtocolParser {
    protected:
        bool m_parsed = false;
        std::vector<std::string> m_command_args;

    public:
        virtual ~IProtocolParser() = default;

        [[nodiscard]] std::vector<std::string>& get_command_args() { return m_command_args; }
        [[nodiscard]] bool is_parsed() const { return m_parsed; }
        virtual void parse_data(std::string& data) = 0;
    };
}
#endif //IPROTOCOLPARSER_HPP
