#ifndef TCPCLIENTSERVICEMANAGER_HPP
#define TCPCLIENTSERVICEMANAGER_HPP

class TcpServerController;

class TcpClientServiceManager {
    private:
        
    public:
        TcpServerController *tcp_ctrlr;

        TcpClientServiceManager(TcpServerController *);
        ~TcpClientServiceManager();
};

#endif