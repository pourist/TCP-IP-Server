#ifndef TCPSERVERCONTROLLER_H
#define TCPSERVERCONTROLLER_H

#include <string>
#include <stdint.h>

class TcpNewConnectionAcceptor;
class TcpClientDbManager;
class TcpClientServiceManager;

class TcpServerController
{
private:
    TcpNewConnectionAcceptor    *tcp_new_conn_acc;
    TcpClientDbManager          *tcp_client_db_mgr;
    TcpClientServiceManager     *tcp_client_svc_mgr;
    
public:
    uint32_t   ip_addr;
    uint16_t   port_no;
    std::string name;

    TcpServerController(uint32_t ip_addr, uint16_t port_no, std::string name);
    ~TcpServerController();
    void    start();
    void    stop();
};

#endif