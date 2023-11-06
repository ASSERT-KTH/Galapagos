#include <sys/select.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

void exit(int status)
{
    void (*real_exit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 120000; // Vary by increasing the delay from 100000 to 120000 micro seconds
    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    fflush(stdout); // add flush before real exit to make sure all buffered streams get flushed.
    real_exit(status);
}