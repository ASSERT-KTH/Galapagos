1. Modifying variables naming and comments.

exit(int response)
{
    void (*func_exit)(int);
    struct timeval time_val;

    time_val.tv_sec = 0;
    time_val.tv_usec = 100000;
    func_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &time_val);
    func_exit(response);
}


2. Changing timeout counter

exit(int status)
{
    void (*myExit)(int);
    struct timeval timeout;

    timeout.tv_sec = 0;
    timeout.tv_usec = 1e5;  // modified this line
    myExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeout);
    myExit(status);
}


3. Swapping statements

exit(int status)
{
    void (*someExit)(int);
    struct timeval tv;

    someExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    select(0, NULL, NULL, NULL, &tv);
    someExit(status);
}


4. Changing waited time to similar value but with different exponent

exit(int status)
{
    void (*aTomatoByAnyOtherName)(int);
    struct timeval timeInterval;

    timeInterval.tv_sec = 0;
    timeInterval.tv_usec = 1*10^5;
    aTomatoByAnyOtherName = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeInterval);
    aTomatoByAnyOtherName(status);
}
