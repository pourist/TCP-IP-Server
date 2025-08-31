#include "TcpNewConnectionAcceptor.hpp"

TcpNewConnectionAcceptor::TcpNewConnectionAcceptor(TcpServerController &controller)
    : tcp_ctrlr(controller)
{
}

TcpNewConnectionAcceptor::~TcpNewConnectionAcceptor() {}

void    TcpNewConnectionAcceptor::startTcpNewConnectionAcceptorThread(){}