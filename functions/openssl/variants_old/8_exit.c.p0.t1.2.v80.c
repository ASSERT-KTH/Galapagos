#include <sys/time.h>
#include <dlfcn.h>

void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    tv.tv_sec = 0;
    tv.tv_usec = 99999;
    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}