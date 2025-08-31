#ifndef TCPCLIENTSERVICEMANAGER_HPP
#define TCPCLIENTSERVICEMANAGER_HPP

class TcpServerController;

class TcpClientServiceManager {
    private:
        TcpClientServiceManager();
        TcpClientServiceManager(const TcpClientServiceManager& src);
        TcpClientServiceManager& operator=(const TcpClientServiceManager& src);

    public:
        TcpServerController &tcp_ctrlr;

        TcpClientServiceManager(TcpServerController &controller);
        ~TcpClientServiceManager();
};

#endif