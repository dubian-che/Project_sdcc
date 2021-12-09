#ifndef BASICCOMM_H
#define BASICCOMM_H
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
//#include <sys/typed.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define U32 unsigned int
#define ROK 0

class basicComm
{

public:
    U32 fd;
    basicComm();
    virtual U32 init() = 0;
    inline U32 getFd() {
        return fd;
    }
};

#endif
