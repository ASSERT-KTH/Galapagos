#include <sys/time.h>
#include <dlfcn.h>
#include <unistd.h>

void exit(int status) {
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 150000; //using 150000 usec provides a slightly longer delay than the original code, but the function still achieves the same result

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    //Adding a flush to stdout before the delay could ensure any pending screen updates are finished before moving on.
    fflush(stdout);
    select(0, NULL, NULL, NULL, &tv);

    realexit(status);
}