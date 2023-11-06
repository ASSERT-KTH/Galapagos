Variant 1:

#include <dlfcn.h>
void exit(int status) 
{
    void (*myexit)(int); 
    struct timeval tval;

    myexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    tval.tv_sec =0;
    tval.tv_usec = 1e5;
    
    select(0, NULL, NULL, NULL, &tval);
    myexit(status);   
}


Variant 2:

#include <sys/time.h>
void exit(int value_to_exit) 
{
    void (*realized_exit)(int); 
    struct timeval timer_value;

    timer_value.tv_sec = 0;
    timer_value.tv_usec = 100000;

    realized_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timer_value);
    realized_exit(value_to_exit);   
}


Variant 3:

#include <dlfcn.h>
void exit(int s) 
{
    void (*ep)(int); 
    struct timeval t;

    t.tv_sec = 0;
    t.tv_usec = 100000;
        
    ep = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &t);
    ep(s);
}


Variant 4:

#include <dlfcn.h>
void exit(int exitStatus) 
{
    void (*officialExit)(int); 
    struct timeval timeValue;

    timeValue.tv_sec = 0;
    timeValue.tv_usec = 100000;

    officialExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeValue);
    officialExit(exitStatus);   
}
