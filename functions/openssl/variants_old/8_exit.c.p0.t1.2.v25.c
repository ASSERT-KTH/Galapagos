exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;
    struct timespec req;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    /* Introducing minor delay using nanosleep */
    req.tv_sec = 0;
    req.tv_nsec = 50000;
    nanosleep(&req, (struct timespec *)NULL);

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status);
}