#include <dlfcn.h>
#include <sys/time.h>
#include <unistd.h>

void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 100000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    sleep(1);
    realexit(status);
}