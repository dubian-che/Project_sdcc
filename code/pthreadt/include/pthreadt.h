#ifndef THREAD_H
#define THREAD_H

#include <thread>
#include "rre.h"

#define THREAD_WORK     0x0000
#define THREAD_UNWORK   0x0001

typedef void(*ThreadFunc)();

class pthreadt
{
    std::thread *threadPtr;
    ThreadFunc threadFunc = nullptr;
    U32 thdCond;
public:
    pthreadt();
    ~pthreadt();
    pthreadt(ThreadFunc);
    U32 init(ThreadFunc);
};



#endif