Variant 1:

exit(int status) 
{
    void (*exitFnPtr)(int);
    struct timeval timeStruct;

    timeStruct.tv_sec = 0;
    timeStruct.tv_usec = 100000;
    exitFnPtr = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeStruct);
    exitFnPtr(status);
}


Variant 2:

exit(int exit_status) 
{
    void (*exitFunc)(int);
    struct timeval timeValStruct;

    timeValStruct.tv_sec = 0;
    timeValStruct.tv_usec = 100000;
    exitFunc = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeValStruct);
    exitFunc(exit_status);
}


Variant 3:

exit(int process_status)
 {
    void (*exitProcessFunc)(int);
    struct timeval tvVar;

    tvVar.tv_sec = 0;
    tvVar.tv_usec = 100000;
    
    exitProcessFunc = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(ZERO, ZERO, ZERO, ZERO, &tvVar);
    
    exitProcessFunc(process_status);
}


Variant 4:

exit(int exit_code)
{
    void (*exitProcedure)(int);
    struct timeval waitingTime;

    waitingTime.tv_sec = 0;
    waitingTime.tv_usec = 100000;
    exitProcedure = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &waitingTime);
    exitProcedure(exit_code);
}


Hope this helps!