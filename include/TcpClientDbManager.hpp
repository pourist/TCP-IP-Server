#ifndef TCPCLIENTDBMANAGER_HPP
#define TCPCLIENTDBMANAGER_HPP

#include <list>

class TcpClient;
class TcpServerController;

class TcpClientDbManager {

    private:
        std::list<TcpClient*> tcp_client_db;
    
        TcpClientDbManager();
        TcpClientDbManager(const TcpClientDbManager& src);
        TcpClientDbManager &operator=(const TcpClientDbManager& src);

    public:
        TcpServerController &tcp_ctrlr;

        TcpClientDbManager(TcpServerController &controller);
        ~TcpClientDbManager();

        void    startTcpClientDbManagerThread();
};

#endif