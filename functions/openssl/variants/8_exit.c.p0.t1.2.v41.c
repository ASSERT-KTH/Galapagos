#include <sys/time.h>
#include <dlfcn.h>

void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 1;      // changed from 0 to 1 second delay before exit
    tv.tv_usec = 0;     // changed from 0.1 to 0 second
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}