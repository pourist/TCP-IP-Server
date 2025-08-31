#include "server_app.hpp"
#include "TcpServerController.hpp"


void    runServerApp(const RuntimeConfig& cfg)
{
    TcpServerController server(cfg.ip_addr_str, cfg.port_no, cfg.name);

    server.start();
}