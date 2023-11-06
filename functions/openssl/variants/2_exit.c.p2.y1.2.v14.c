#include <sys/time.h>
#include <dlfcn.h>

void exit(int status)
{
    int debounce = 100000; // Use a named constant instead of hardcoded value
    struct timeval tv = {0};
    void (*realexit)(int);

    tv.tv_usec = debounce; 
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}