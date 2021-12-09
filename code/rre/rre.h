#ifndef RRE_H
#define RRE_H

#define U32 unsigned int


#define RETURN_IF(bool_t, ret) \
    if (bool_t) { \
        return ret; \
    } \

#define RETURN_IF_NULL(_ptr, ret) \
    if (_ptr == nullptr) { \
        return ret; \
    } \

#define RRE_DELETE(_ptr) \
    if (_ptr != nullptr) { \
        delete _ptr; \
    } \

#endif