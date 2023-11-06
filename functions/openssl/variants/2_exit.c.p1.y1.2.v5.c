1. Reordering the non-dependent operations:


exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_usec = 100000;
    tv.tv_sec = 0;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);

    realexit(status);
}


2. Using temp variable:


exit(int status)
{
    struct timeval tv_temp;
    
    tv_temp.tv_sec = 0;
    tv_temp.tv_usec = 100000;
    
    struct timeval tv = tv_temp;
    
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    select(0, 0, 0, 0, &tv);
    realexit(status);
}


3. Reshuffling locators  
   NOTE: This assumes 'dlsym()' does not have side effects affecting the other two commands


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


4. Defining struct timeval variables independently


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


5. Initializing timeval literal:


exit(int status)
{
    void (*realexit)(int);
    struct timeval tv = {0, 100000};

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, 0, 0, 0, &tv);
    realexit(status);
}
