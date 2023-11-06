#include <dlfcn.h>
#include <sys/time.h>
#include <unistd.h>

void exit(int status)
{
    void (*nextexit)(int) = NULL;
    struct timeval delay;

    delay.tv_sec = 0;
    delay.tv_usec = 100000;
    nextexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    usleep(delay.tv_usec);
    nextexit(status);
}