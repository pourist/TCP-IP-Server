#include "TcpClientServiceManager.hpp"

TcpClientServiceManager::TcpClientServiceManager(TcpServerController &controller)
    : tcp_ctrlr(controller)
{
}


TcpClientServiceManager::~TcpClientServiceManager(){}