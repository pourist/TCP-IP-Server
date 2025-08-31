#include "config_temp/temp_pars_config.hpp"
#include "network_utils.hpp"

#include <cstdlib>    // strtol
#include <cerrno>     // errno
#include <stdexcept>
#include <string>

void    parseTempConfig(int argc, char** argv, RuntimeConfig& cfg)
{
    if (argc != 4)
            throw std::runtime_error("Usage: <program> <ip> <port> <name>");

    cfg.ip_addr_str = argv[1];
    if (cfg.ip_addr_str.empty()) {
        throw std::runtime_error("Invalid name: empty");
    }

    errno = 0;
    char* endptr = 0;
    long port = std::strtol(argv[2], &endptr, 10);
    if (errno != 0 || *endptr != '\0')
        throw std::runtime_error(std::string("Invalid port: ") + argv[2]);
    if (port < 0 || port > 65535)
        throw std::runtime_error("Port out of range (0–65535)");
    cfg.port_no = static_cast<uint16_t>(port);

    cfg.name = argv[3];
    if (cfg.name.empty()) {
        throw std::runtime_error("Invalid name: empty");
    }
}