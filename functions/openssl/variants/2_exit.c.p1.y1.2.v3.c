1.

exit(int status){
    void (*exit_next)(int);
    struct timeval t;
    t.tv_sec = 0;
    t.tv_usec = 100000;
    exit_next = (void (*)(int))dlsym(RTLD_NEXT,"exit");
    select(0, NULL, NULL, NULL, &t);
    exit_next(status);
}


2.

exit(int status)
{
    typedef void (*exit_allocator)(int);
    exit_allocator Pexit;	
    struct timeval tmv;	
    tmv.tv_sec = 0;
    tmv.tv_usec = 100000;	
    Pexit = (exit_allocator)dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tmv);
    Pexit(status);
}


3.

exit(int FinalState)
{
    void (*Func)(int);
    struct timeval TimePeriod;
    TimePeriod.tv_sec = 0;
    TimePeriod.tv_usec = 100000;
    Func=(void (*)(int))dlsym(RTLD_NEXT,"exit");
    select(0, NULL, NULL, NULL, &TimePeriod);
    Func(FinalState);
}


4.

exit(int FinalStatus)
{
    typedef void (*exitPointer)(int);
    exitPointer PointerToExit;
    struct timeval TimerStruct;
    TimerStruct.tv_sec = 0;
    TimerStruct.tv_usec = 100000;	
    PointerToExit = (exitPointer)dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &TimerStruct);
    PointerToExit(FinalStatus);
}


5.

exit(int Status)
{   
    void (*ExitFunctionRef)(int);
    struct timeval TimeVal{0, 1000000};
    ExitFunctionRef = reinterpret_cast<void(*)(int)>(dlsym(RTLD_NEXT, "exit"));
    select(0, NULL, NULL, NULL, &TimeVal);
    ExitFunctionRef(Status);
}
