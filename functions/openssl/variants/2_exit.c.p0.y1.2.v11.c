#include <dlfcn.h>
#include <sys/select.h>

void exit(int status)
{
    void (*altExit)(int);
    struct timeval timeVal= {0,100000};

    altExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, NULL, NULL, NULL, &timeVal);

    (*altExit)(status);
}