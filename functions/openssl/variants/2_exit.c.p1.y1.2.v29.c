1) Reordering the execution of instructions:


exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;
    
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    select(0, 0, 0, 0, &tv);
    realexit(status);
}

2) Using 'memset' function for initializing 'struct timeval tv':


#include <string.h> // Required for memset

exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    memset(&tv, 0, sizeof(tv));
    tv.tv_usec = 100000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status);
}


3) Introducing temporary variable for exit status:


exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;
    int tmp_status = status;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(tmp_status);
}


4) Introducing temporary variable for function pointer:


exit(int status)
{
    void (*realexit_tmp)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    realexit_tmp = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit_tmp(status);
}
