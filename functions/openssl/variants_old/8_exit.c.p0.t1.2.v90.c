#include <dlfcn.h>
#include <sys/time.h> 


void exit(int status)
{
    void (*realExit)(int);
    struct timeval delayTime;

    delayTime.tv_sec = 0;
    delayTime.tv_usec = 200000;
    realExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &delayTime);
    realExit(status);
}