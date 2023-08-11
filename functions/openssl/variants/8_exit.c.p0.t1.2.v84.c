#include <dlfcn.h>
#include <sys/select.h>
#include <unistd.h>

void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    usleep(100000); // using usleep instead of select for pausing

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    if(realexit != NULL) // Check to see if the realexit function was identified correctly
    {  
       realexit(status);
    }
    else
    {
        _Exit(status); // Fall back to the _Exit status if realexit function wasn't correctly identified
    }
}