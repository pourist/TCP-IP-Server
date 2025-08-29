#ifndef TCPCLIENTDBMANAGER_HPP
#define TCPCLIENTDBMANAGER_HPP

#include <list>

class TcpClient;
class TcpServerController;

class TcpClientDBManager {

    private:
        std::list<TcpClient*>tcp_client_db;
    
    public:
        TcpServerController *tcp_ctrlr;

        TcpClientDBManager(TcpServerController *);
        ~TcpClientDBManager();
};

#endif