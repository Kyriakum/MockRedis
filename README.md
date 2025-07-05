## MockRedis
### This is my own implementation of Redis.

#### What is Redis?

Redis (REmote DIctionary Server) is an open source, in-memory, NoSQL key/value store that is used primarily as an application cache or quick-response database.

It can also work as a *Message Broker*, but I will first be implementing the cache as described above.

### My Architecture

I'm using **ASIO** for Network I/O and async client handling which leverages the *Reactor Pattern* (using *epoll* on Linux).

**Server Loop:**

* **Server** infinitely loops through a function which implements an *async_accept* callback, so as to never have **io_context** terminate and always accept new clients.
* **ClientSession** similarly infinitely loops through a sequence of functions that receive data and send data back to the client of the respective **ClientSession**.

**Command System:** *(from parsing to executing)*

* **CommandRegistrar** holds a registry with key-pair values of the *string* that triggers a command with the corresponding **Command Singleton object**.
* Commands auto-register through **AutoRegister** using the macro *REGISTER_COMMAND(CommandType, CommandName)* which just instantiates an AutoRegister object which adds the pair to the registry.
* **IParserProvider** provides an **IProtocolParser** object. This is needed because an **IProtocolParser** needs to hold state throughout its lifetime.
* **IProtocolParser** parses the arguments passed by the client.
* **ICommandParser** parses the command and delegates it along with its arguments to the corresponding **Command Singleton object**.
* **Command** classes implement specific commands to handle (e.g., **PingCommand** handles PING).
