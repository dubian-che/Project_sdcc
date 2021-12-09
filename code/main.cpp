#include "tcpComm.h"
#include <iostream>

int main()
{
    tcpComm comm;
    int a = comm.init();
    std::cout<<a<<std::endl;
    comm.tcplisten();
    comm.tcpAccept();

    
}