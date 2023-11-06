#include <unistd.h>

exit(int status)
{
    void (*realexit)(int);
    struct timespec req, rem;
 
    req.tv_sec = 0;
    req.tv_nsec = 100000000L;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    nanosleep(&req, &rem);
    realexit(status);
}