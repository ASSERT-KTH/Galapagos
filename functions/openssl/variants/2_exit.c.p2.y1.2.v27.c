#include <sys/time.h>
#include <dlfcn.h>

void exit(int status)
{
    void (*myexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 50 * 2 * 1000;
    myexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    myexit(status);
}