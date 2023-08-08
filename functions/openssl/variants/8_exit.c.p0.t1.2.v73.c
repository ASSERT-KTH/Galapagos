void exit(int status)
{
    void (*delayedExit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000; // duration of delay was increased from 100000 to 200000
    delayedExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    delayedExit(status);
}