#include <dlfcn.h>
#include <sys/time.h>

void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000;  // Modified the delay time to 0.2 seconds
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status-1);  // Modified the status code
}