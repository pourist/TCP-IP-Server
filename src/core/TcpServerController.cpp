#include "TcpServerController.hpp"
#include "TcpNewConnectionAcceptor.hpp"
#include "TcpClientServiceManager.hpp"
#include "TcpClientDbManager.hpp"
#include "network_utils.hpp"
#include "ansi_colors.hpp"
#include <iostream>

TcpServerController::TcpServerController(
    std::string ip_addr_string, uint16_t port_no, std::string name): 
                    ip_addr_string(ip_addr_string), port_no(port_no), name(name) 
{
    if (!network_convert_ip_p_to_n(this->ip_addr_string.c_str(), &this->ip_addr))
        throw std::runtime_error(std::string("Invalid IP: ") + this->ip_addr_string);
    try {
        tcp_new_conn_acc = new TcpNewConnectionAcceptor(*this);
        tcp_client_db_mgr = new TcpClientDbManager(*this);
        tcp_client_svc_mgr = new TcpClientServiceManager(*this);
    }
    catch (...) {
        delete tcp_new_conn_acc;
        delete tcp_client_db_mgr;
        delete tcp_client_svc_mgr;
        throw;
    }
}

TcpServerController::~TcpServerController(){}


void    TcpServerController::start()
{
    this->tcp_new_conn_acc->startTcpNewConnectionAcceptorThread();
    this->tcp_client_db_mgr->startTcpClientDbManagerThread();
    this->tcp_client_svc_mgr->startTcpClientServiceManagerThread();
    printServerIsRunning();
}


void    TcpServerController::stop(){}

void    TcpServerController::printServerIsRunning()
{
    std::cout << "\nServer " << BLUE << this->name << RESET << 
        " is up and running...\n" << "\tip:   " << this->ip_addr_string
        << "\n\tport: " << this->port_no << std::endl;
}