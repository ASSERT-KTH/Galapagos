#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/time.h>
#include <unistd.h>

void exit(int status) 
{
    void (*newExit)(int);
    struct timeval timeValue;

    timeValue.tv_sec = 2; 
    timeValue.tv_usec = 200000; 
 
    newExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    usleep((timeValue.tv_sec * 1000000UL) + timeValue.tv_usec); 
    
    newExit(status);
}