#include "pthreadt.h"
#include "rre_errcode.h"

pthreadt::pthreadt()
{
    thdCond = THREAD_UNWORK;
}

pthreadt::pthreadt(ThreadFunc func)
{
    threadFunc = func;
    thdCond = THREAD_UNWORK;
}

pthreadt::~pthreadt()
{
    RRE_DELETE(threadPtr);
}

U32 pthreadt::init(ThreadFunc func)
{
    if (func != nullptr) {
        threadFunc = func;
    }
    threadPtr = new std::thread(threadFunc);
    RETURN_IF_NULL(threadPtr, MEM_NEW_ERR);
    threadPtr->join();
    thdCond = THREAD_WORK;
    return ROK;
}

