Variant 1:


exit(int status)
{
    struct timeval tv;
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    select(0, NULL, NULL, NULL, &tv);
    
    realexit(status);
}


Variant 2:


exit(int status)
{
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    struct timeval tv = {0, 100000};
    
    select(0, NULL, NULL, NULL, &tv);
    (*realexit)(status);
}


Variant 3:


exit(int status)
{
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    (*realexit)(status);
}
