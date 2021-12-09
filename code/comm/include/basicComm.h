#ifndef BASICCOMM_H
#define BASICCOMM_H
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
//#include <sys/typed.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "rre.h"
#include "rre_errcode.h"



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
