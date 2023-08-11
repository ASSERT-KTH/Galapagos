exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;
    struct timespec req, rem;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    req.tv_sec = tv.tv_sec;
    req.tv_nsec = tv.tv_usec* 1000;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    nanosleep(&req , &rem);

    realexit(status);
}
