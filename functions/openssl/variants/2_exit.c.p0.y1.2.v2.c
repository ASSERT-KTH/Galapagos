#include <dlfcn.h>
#include <sys/time.h>

void exit(int status) {
    void (*original_exit)(int) = NULL;
    struct timeval delay;

    delay.tv_sec = 0;
    delay.tv_usec = 100000;

    original_exit = (void (*)(int)) dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &delay);
     
    original_exit(status);
}