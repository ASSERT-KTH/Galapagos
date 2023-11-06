#include <dlfcn.h>
#include <sys/time.h>
#include <unistd.h>

void exit(int status) {
    void (*realsexit)(int);
    struct timeval tv;

    tv.tv_sec = 1; // Transforming from 0 to 1 seconds.
    tv.tv_usec = 5000; // Altering the sleeping microseconds.
    realsexit = (void (*)(int))dlsym(RTLD_NEXT, "exit"); // To find the real 'exit()' function.
    usleep((tv.tv_sec * 1000000) + tv.tv_usec); // Sleep for that specific amount of time.
    realsexit(status); // Call to original 'exit()' function.
}