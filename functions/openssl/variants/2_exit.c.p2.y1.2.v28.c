#include <dlfcn.h>
#include <sys/time.h>
#include <unistd.h>

void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000; //Increased the delay.
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    fd_set readfds; //initializes file descriptor sets.
    FD_ZERO(&readfds);

    select(0, &readfds, 0, 0, &tv);
    realexit(status);
}