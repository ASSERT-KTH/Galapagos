void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    if (status != 0)
    {
        tv.tv_usec = 200000;
    }
    else 
    {
        tv.tv_usec = 100000;
    }
    
    select(0, 0, 0, 0, &tv);
    
    realexit(status);
}