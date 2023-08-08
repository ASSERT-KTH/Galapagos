#include <stdlib.h>
#include <sys/time.h>
#include <dlfcn.h>

void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 75000; // Varying the delay to 75000 microseconds
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status);
}