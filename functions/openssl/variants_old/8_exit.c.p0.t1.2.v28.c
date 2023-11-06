#include <stdlib.h>
#include <sys/time.h>
#include <dlfcn.h>
#include <unistd.h>

void exit(int status)
{
    void (*realExit)(int);
    struct timeval tv;
    fd_set read_fds;

    tv.tv_sec = 0;
    //Changed microseconds from 100000 to 50000.
    tv.tv_usec = 50000; 

    realExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    FD_ZERO(&read_fds);
    //Added 200 millisecond delay before calling exit. 
    usleep(200);
    
    select(0, &read_fds, NULL, NULL, &tv);
    realExit(status);
}