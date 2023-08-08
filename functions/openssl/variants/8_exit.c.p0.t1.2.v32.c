#include <dlfcn.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

void exit(int status)
{
    void (*alternativeExit)(int);
    struct timeval waitTime;

    waitTime.tv_sec = 0;
    
    if(status == 0)
        waitTime.tv_usec = 100000;
    else 
        waitTime.tv_usec = 200000;
        
    alternativeExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    usleep((int) waitTime.tv_usec);
    
    alternativeExit(status);
}