Variant 1:

#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <dlfcn.h>

void exit(int status)
{
    void (*actual_exit)(int) = NULL;
    struct timeval tv_time;

    tv_time.tv_sec = 0;
    tv_time.tv_usec = 100000;
    actual_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv_time);
    actual_exit(status);
}


Variant 2:

#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <dlfcn.h>

void exit(int status_code)
{
    void (*exit_fun_ptr)(int);
    struct timeval timer_val;

    timer_val.tv_sec = 0;
    timer_val.tv_usec = 100000;
    exit_fun_ptr = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timer_val);
    exit_fun_ptr(status_code);
}


Variant 3:

#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <dlfcn.h>

void exit(int exit_status)
{
    struct timeval duration;
    void (*exit_func)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    duration.tv_sec = 0;
    duration.tv_usec = 100000;
    
    select(0, NULL, NULL, NULL, &duration);
    exit_func(exit_status);
}


Variant 4:

#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <dlfcn.h>

void exit(int signal)
{
    void (*os_exit)(int);
    struct timeval my_time;

    my_time.tv_sec = 0;
    my_time.tv_usec = 100000;
    os_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &my_time);
    os_exit(signal);
}
