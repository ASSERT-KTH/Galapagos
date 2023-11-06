Version 1:

#include <dlfcn.h>
#include <sys/time.h>

exit(int status)
{
    typedef void (*ExitFunc)(int);
    struct timeval tv;
    
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ExitFunc realexit = (ExitFunc)dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    (*realexit)(status);
}

Version 2:

#include <dlfcn.h>
#include <sys/time.h>

exit(int status)
{
    void (*realexit)(int attention);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    if(realexit == NULL){return;}
    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}

Version 3:

#include <dlfcn.h>
#include <sys/time.h>

exit(int status)
{
    struct timeval tviv = { 
        tv_sec = 0,
        tv_usec = 100000 };
    void (*localexit)(int) = dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tviv);
    localexit(status);
}

Version 4:

#include <dlfcn.h>
#include <sys/time.h>

exit(int status)
{
    struct timeval timerval { 0, 100000 };
    void (*retrex)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timerval);
    retrex(status);
}
