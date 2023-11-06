#include <stdlib.h>
#include <dlfcn.h>
#include <sys/select.h>
#include <sys/time.h>

void exit(int status) {
    // function pointer
    void (*realexit)(int);   

    // struct for time delay
    struct timeval tv;

    // set the time values
    tv.tv_sec = 1;   // seconds
    tv.tv_usec = 25000;   // microseconds   

    // fetch the real exit function
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    // make the pause slightly longer
    select(0, NULL, NULL, NULL, &tv);  

    // call the real exit function
    realexit(status);   
}
