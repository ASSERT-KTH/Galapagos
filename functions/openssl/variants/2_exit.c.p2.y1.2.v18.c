void exit(int status)
{
    void (*realexit)(int);
    struct timespec ts;

    ts.tv_sec = 0;
    ts.tv_nsec = 100000000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    nanosleep(&ts, NULL);
    realexit(status);
}