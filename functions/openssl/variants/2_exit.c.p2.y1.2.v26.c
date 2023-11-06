#include <sys/select.h>
#include <dlfcn.h>
#include <unistd.h>

void exit(int status)
{
    void (*original_exit)(int) = NULL;
    struct timeval delay_time;

    delay_time.tv_sec = 0;
    delay_time.tv_usec = 200000; // Doubling the initial delay time

    original_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    if (original_exit != NULL)
    {
        // Using the maximum value of nfds to avoid invalid nfds
        select(FD_SETSIZE, NULL, NULL, NULL, &delay_time);

        original_exit(status);
    }
}