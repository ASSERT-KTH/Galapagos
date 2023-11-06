#include <unistd.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <sys/time.h>

void exit(int status)
{
    void (*real_exit)(int) = NULL;
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;

    real_exit = (void(*)(int))dlsym(RTLD_NEXT, "exit");

    usleep(tv.tv_sec * 1000000L); // this sets the sleep time in microsecs instead

    real_exit(status);
}