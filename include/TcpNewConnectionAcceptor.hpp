#ifndef TCPNEWCONNECTIONACCEPTOR_HPP
#define TCPNEWCONNECTIONACCEPTOR_HPP

class TcpServerController;

class TcpNewConnectionAcceptor {
    private:
        TcpNewConnectionAcceptor();
        TcpNewConnectionAcceptor(const TcpNewConnectionAcceptor& src);
        TcpNewConnectionAcceptor &operator=(const TcpNewConnectionAcceptor& src);

    public:
        TcpServerController &tcp_ctrlr;

        TcpNewConnectionAcceptor(TcpServerController &controller);
        ~TcpNewConnectionAcceptor();

        void    startTcpNewConnectionAcceptorThread();
};


#endif