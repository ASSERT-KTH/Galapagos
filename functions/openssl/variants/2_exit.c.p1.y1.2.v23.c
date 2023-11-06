Variant 1:

#include <dlfcn.h>

void exit(int status) {
    void (*realexit)(int);
    struct timeval tv = { 0, 100000 };

    realexit = (void (*)(int)) dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    (*realexit)(status);
}

Variant 2:

#include <dlfcn.h>

void exit(int status) {
    void (*newexit)(int);
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    newexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    newexit(status);
}

Variant 3:

#include <dlfcn.h>

void exit(int status) {
    typedef void exit_func(int);
    exit_func* exitPoint;

    struct timeval 
    {
        long tv_sec;
        long tv_usec;
    } exitDelay = {0, 100000};

    exitPoint = (exit_func*)dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, (struct timeval*)&exitDelay);
    exitPoint(status);
}

Variant 4:

#include <dlfcn.h>

void exit(int status) {
    void (*curr_exit)(int);
    struct timeval timerval;

    timerval.tv_sec = 0; 
    timerval.tv_usec = 100000; 

    curr_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit"); 
    select(0, 0, 0, 0, &timerval); 
    curr_exit(status);
}
