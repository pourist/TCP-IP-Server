#ifndef TCPSERVERCONTROLLER_HPP
#define TCPSERVERCONTROLLER_HPP

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
    
    TcpServerController();
    TcpServerController(const TcpServerController&);
    TcpServerController& operator=(const TcpServerController&); // not implemented

public:
    std::string ip_addr_string;
    uint32_t    ip_addr;
    uint16_t    port_no;
    std::string name;

    TcpServerController(std::string ip_addr_string, uint16_t port_no, std::string name);
    ~TcpServerController();


    void    start();
    void    stop();

    void    printServerIsRunning();
};

#endif