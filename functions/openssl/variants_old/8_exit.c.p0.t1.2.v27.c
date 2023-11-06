#include <sys/time.h>
#include <dlfcn.h>

void exit(int status)
{
    void (*actualExit)(int);
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 50000;
    actualExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    actualExit(status);
}