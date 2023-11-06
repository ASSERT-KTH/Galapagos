// Variant 1: Changing the order by initializing realexit first
exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    select(0, 0, 0, 0, &tv);
    realexit(status);
}

// Variant 2: Changing waiting time for select syscall

exit(int status)
{  
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status);
}

// Variant 3: Directly initializing tv struct without mentioning tv_sec and tv_usec individually
exit(int status)
{ 
    void (*realexit)(int);
    struct timeval tv = {0, 100000};

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status);
}  

// Variant 4: Calling the real exit last after initializing the struct and finding the real exit function 

exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status);
}