#ifndef RUNTIME_CONFIG_HPP
#define RUNTIME_CONFIG_HPP

#include <stdint.h>
#include <string>

struct RuntimeConfig {
    uint32_t    ip_addr;   // IPv4, network byte order
    uint16_t    port_no;   // host byte order
    std::string name;
};

void parseTempConfig(int argc, char** argv, RuntimeConfig& cfg);

#endif // RUNTIME_CONFIG_HPP
