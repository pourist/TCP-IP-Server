#include "TcpServerController.hpp"
#include "TcpNewConnectionAcceptor.hpp"
#include "TcpClientServiceManager.hpp"
#include "TcpClientDbManager.hpp"
#include "network_utils.hpp"
#include <iostream>

TcpServerController::TcpServerController(
    uint32_t ip_addr, uint16_t port_no, std::string name): 
                    ip_addr(ip_addr), port_no(port_no), name(name) 
{
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


void    TcpServerController::start(){}
void    TcpServerController::stop(){}