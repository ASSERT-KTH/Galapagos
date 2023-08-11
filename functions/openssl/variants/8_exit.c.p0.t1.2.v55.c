#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/time.h>

void exit(int status)
{
    void (*actual_exit)(int);
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 200000;
    actual_exit = dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    actual_exit(status);
}