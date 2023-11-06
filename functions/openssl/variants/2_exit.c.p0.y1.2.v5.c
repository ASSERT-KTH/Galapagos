void exit(int status)
{
    void (*actualExit)(int);
    struct timespec ts;
 
    ts.tv_sec = 0;
    ts.tv_nsec = 100 * 1000000;
    actualExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    nanosleep(&ts, NULL);
    actualExit(status);
}