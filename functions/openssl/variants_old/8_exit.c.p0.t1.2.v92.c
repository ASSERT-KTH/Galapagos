#include <dlfcn.h>
#include <sys/time.h>
#include <unistd.h>

void exit(int status)
{
    void (*alternateExit)(int);
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 50000;
    alternateExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    usleep(tv.tv_sec * 1000000 + tv.tv_usec);
    alternateExit(status);
}