#include <dlfcn.h>
#include <stdlib.h>
#include <sys/select.h>

void exit(int status)
{
    int (*realexit)(int);
    fd_set readfds;
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 50000;
    realexit = (int (*)(int))dlsym(RTLD_NEXT, "exit");
    FD_ZERO(&readfds);

    select(0, &readfds, NULL, NULL, &tv);

    realexit(status);
}