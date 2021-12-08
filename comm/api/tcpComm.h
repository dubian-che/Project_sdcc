#ifndef TCPCOMM_H
#define TCPCOMM_H
#include "basicComm.h"

#define TCP_SOCKET_ERR          0x1001
#define TCP_BIND_ERR            0x1002
#define TCP_LISTEN_ERR          0x1003

class tcpComm:public basicComm
{
    sockaddr_in addr;
    U32 cfd;
public:
    tcpComm();
    U32 init();
    U32 listen();
    virtual U32 work();
};

#endif
