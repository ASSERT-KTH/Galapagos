// Program variant using usleep function for delay
// instead of select function.

#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>

void exit(int status)
{
    void (*realexit)(int);
      
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    usleep(100000);  // sleep for 100000 microseconds or 0.1 second
    realexit(status);
}