#ifndef PINGCOMMAND_HPP
#define PINGCOMMAND_HPP

#include "Command.hpp"
#include "Singleton.hpp"
#include "AutoRegister.hpp"

namespace RedisCommand {

class PingCommand : public Command, public Singleton<PingCommand> {
      friend class Singleton<PingCommand>;
      PingCommand() : Singleton<PingCommand>(), Command() {};

  public:
      void execute() override {
          LOG_INFO("Called PingCommand");
      }
};

REGISTER_COMMAND(PingCommand, "PING");
}
#endif //PINGCOMMAND_HPP
