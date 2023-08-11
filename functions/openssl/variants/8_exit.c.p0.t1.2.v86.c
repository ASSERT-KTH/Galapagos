void exit(int status)
{
    void (*realexit)(int) = NULL;
    struct timeval tv;
    
    tv.tv_sec = 0;
    tv.tv_usec = 50000; // changed delay from 100000 microseconds to 50000
    realexit  = (void (*)(int)) dlsym(RTLD_NEXT, "exit"); 

    select(0, 0, 0, 0, &tv);
    if(realexit != NULL)
        realexit(status); // added null pointer check before calling realexit function
    else
        _exit(status); // added alternative system call to exit if realexit is inaccessible
}