#ifndef RESPPARSER_HPP
#define RESPPARSER_HPP

#include "IProtocolParser.hpp"
#include <Logging.h>

namespace RedisProtocol {
    class RespParser final : public IProtocolParser {
      int total_loops = 0;
      int current_loop = 0;

      enum ParseState {
          ARR_LENGTH,
          BULK_LENGTH,
          BULK
      };

      ParseState m_state = ARR_LENGTH;

      void next_state() {
          if (m_state == ARR_LENGTH) {
              m_state = BULK_LENGTH;
          }
          else if (m_state == BULK_LENGTH) {
              m_state = BULK;
          } else m_state = BULK_LENGTH;
      }
      public:
          void parse_data(std::string& data) override;
          int parse_arr_length(const std::string& data);
          int parse_bulk_length(const std::string& data);
          void parse_bulk(const std::string &data);
    };
}
#endif //RESPPARSER_HPP
