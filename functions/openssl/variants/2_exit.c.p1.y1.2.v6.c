Variant 1:

exit(int status)
{
    void (*funcPtr)(int);
    struct timeval timing;

    timing.tv_sec = 0;
    timing.tv_usec = 100000;
    funcPtr = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timing);
    funcPtr(status);
}


Variant 2:

exit(int exitStatus)
{
    void (*funcExit)(int);
    struct timeval delayTime;

    delayTime.tv_sec = 0;
    delayTime.tv_usec = 100000;
    funcExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &delayTime);
    funcExit(exitStatus);
}


Variant 3:

exit(int exitCode)
{
    void (*exitFunction)(int);
    struct timeval timeStruct;

    timeStruct.tv_sec = 0;
    timeStruct.tv_usec = 100000;
    exitFunction = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeStruct);
    exitFunction(exitCode);
}


Variant 4:

exit(int myStatus)
{
    void (*funcToExit)(int);
    struct timeval tvToDelay;

    tvToDelay.tv_sec = 0;
    tvToDelay.tv_usec = 100000;
    funcToExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tvToDelay);
    funcToExit(myStatus);
}

