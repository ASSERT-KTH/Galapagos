Variant 1:

exit(int status)
{
    void (*exitPtr)(int);
    struct timeval exitTimeVal;

    exitTimeVal.tv_sec = 0;
    exitTimeVal.tv_usec = 100000;
    exitPtr = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &exitTimeVal);
    exitPtr(status);
}


Variant 2:

exit(int newStatus)
{
    void (*newexit)(int);
    struct timeval tvObj;
  
    tvObj.tv_sec = 0;
    tvObj.tv_usec = 100000;
    newexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
  
    select(0, NULL, NULL, NULL, &tvObj);
    newexit(newStatus);
}


Variant 3:

exit(int exitStatus)
{
    void (*exitFunction)(int);
    struct timeval exitClock;

    exitClock.tv_sec = 0;
    exitClock.tv_usec = 100000;
    exitFunction = (void (*)(int))dlsym(RTLD_NEXT, "exit");
  
    select(0, 0, 0, 0, &exitClock);
    exitFunction(exitStatus);
}


Variant 4:

exit(int stat)
{
    void (*funcExit)(int);
    struct timeval timeVal;

    timeVal.tv_sec = 0;
    timeVal.tv_usec = 100000;
    funcExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, NULL, NULL, NULL, &timeVal);
    funcExit(stat);
}
