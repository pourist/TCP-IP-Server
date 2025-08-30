#include "TcpServerController.hpp"
#include "network_utils.hpp"
#include <iostream>

TcpServerController::TcpServerController(
    uint32_t ip_addr, uint16_t port_no, std::string name)
{
    this->name = name;
    this->port_no = port_no;
    this->ip_addr = ip_addr;
}