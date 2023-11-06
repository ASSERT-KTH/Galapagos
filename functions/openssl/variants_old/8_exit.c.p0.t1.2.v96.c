#include <sys/time.h>
#include <dlfcn.h>

void exit(int status) 
{
    void (*alt_exit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 50000; // Halving the original delay
    alt_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv); // Using NULL instead of 0 for remaining arguments
    alt_exit(status);
}