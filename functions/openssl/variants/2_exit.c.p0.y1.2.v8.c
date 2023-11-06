#include <stddef.h>
#include <dlfcn.h>
#include <sys/select.h>

void exit(int status)
{
    typedef void (*ExitFunc)(int);
    struct timeval delayInterval;

    delayInterval.tv_sec = 0;
    delayInterval.tv_usec = 100000;

    ExitFunc originalExit = NULL;
    originalExit = (ExitFunc)dlsym(RTLD_NEXT, "exit");

    select(0, NULL, NULL, NULL, &delayInterval);

    originalExit(status);
}
