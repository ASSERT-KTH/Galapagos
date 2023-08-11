#include <dlfcn.h>
#include <sys/time.h>
#include <unistd.h>

void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;
    fd_set fdset;

    tv.tv_sec = 2;  
    tv.tv_usec = 50000;  

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    FD_ZERO(&fdset);  
    select(FD_SETSIZE, &fdset, NULL, NULL, &tv);
    
    realexit(status);
}