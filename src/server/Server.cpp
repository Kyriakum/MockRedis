#include "Server.hpp"

int RedisServer::create_server_socket(int port) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Error creating server socket" << std::endl;
        return -1;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htonl(port);

    if (bind(server_fd, reinterpret_cast<sockaddr *>(&addr), sizeof(addr)) < 0) {
        std::cerr << "Error binding server socket" << std::endl;
        close(server_fd);
        return -1;
    }

    if (listen(server_fd, BACKLOG) < 0) {
        std::cerr << "Error listening on server socket" << std::endl;
        close(server_fd);
        return -1;
    }
    return server_fd;
}
