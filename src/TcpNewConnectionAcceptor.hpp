#ifndef TCPNEWCONNECTIONACCEPTOR_HPP
#define TCPNEWCONNECTIONACCEPTOR_HPP

class TcpServerController;

class TcpNewConnectionAcceptor {
    private:
        
    public:
        TcpServerController *tcp_ctrlr;

        TcpNewConnectionAcceptor(TcpServerController *);
        ~TcpNewConnectionAcceptor();
};


#endif