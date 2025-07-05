#include "RespParser.hpp"

void RedisProtocol::RespParser::parse_data(std::string& data) {
    LOG_INFO("Parsing data");
    if (m_state == ARR_LENGTH) {
        total_loops = parse_arr_length(data);
    } else if (m_state == BULK_LENGTH) {
        // Does nothing for now
        parse_bulk_length(data);
    } else {
        parse_bulk(data);
        current_loop++;
    }

    if (current_loop == total_loops) {
        m_parsed = true;
        return;
    }
    next_state();
}

int RedisProtocol::RespParser::parse_arr_length(const std::string &data) {
    return std::stoi(data.substr(1));
}

int RedisProtocol::RespParser::parse_bulk_length(const std::string &data) {
    return std::stoi(data.substr(1));
}

void RedisProtocol::RespParser::parse_bulk(const std::string &data) {
    auto i = data;
    std::erase(i, '\r');
    m_command_args.push_back(i);
}

