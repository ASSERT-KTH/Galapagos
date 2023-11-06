
#include <dlfcn.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

exit(int status)
{
    void (*realExit)(int);
    struct timeval timeValue;

    timeValue.tv_sec = 0;
    timeValue.tv_usec = 100000;

    realExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    usleep(100000);
  
    realExit(status);
}
