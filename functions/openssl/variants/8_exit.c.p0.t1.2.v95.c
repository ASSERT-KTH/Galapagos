#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/time.h>
#include <assert.h>

void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 1000;
    
    realexit = dlsym(RTLD_NEXT, "exit");
    assert(realexit);
    
    printf("Executing custom exit code with status %d:\n", status);
    
    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}