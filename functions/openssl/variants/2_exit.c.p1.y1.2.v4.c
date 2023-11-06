Variant 1:

#include <stdlib.h>
#include <sys/time.h>
#include <dlfcn.h>

exit(int status){
    void (*realexit)(int);
    struct timeval timeValue;

    timeValue.tv_sec = 0;
    timeValue.tv_usec = 100000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeValue);
    (*realexit)(status);
}


Variant 2:

#include <stdlib.h>
#include <sys/time.h>
#include <dlfcn.h>

exit(int exitStatus){
    void (*myExitFunc)(int);
    struct timeval timeValField;

    timeValField.tv_sec = 0;
    timeValField.tv_usec = 100000;
    myExitFunc = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeValField);
    myExitFunc(exitStatus);
}


Variant 3:

#include <stdlib.h>
#include <sys/time.h>
#include <dlfcn.h>

exit(int status_para){
    void (*exit_func)(int);
    struct timeval tv_var;

    tv_var.tv_sec = 0;
    tv_var.tv_usec = 100000;
    exit_func= (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv_var);
    (*exit_func)(status_para);
}
