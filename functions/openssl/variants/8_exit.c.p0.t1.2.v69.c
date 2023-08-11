#include <dlfcn.h>
#include <sys/select.h>
#include <unistd.h>

void exit(int status)
{
    void (*real_exit)(int);
    struct timeval timeout;

    timeout.tv_sec = 0;
    timeout.tv_usec = 150000; // Increase waiting time before exit
    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    usleep(timeout.tv_usec); // Modified to use usleep 
    real_exit(status);
}