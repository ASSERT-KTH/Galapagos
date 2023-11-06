#include <dlfcn.h>
#include <sys/time.h>

void exit(int status)
{
    void (*customexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 75; // transforming the microseconds for delay by less.
    
    customexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    // increasing polling count.
    for (int i = 0; i < 3; i++) 
        select(0, 0, 0, 0, &tv); 

    customexit(status);
}