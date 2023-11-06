void exit(int status)
{
    void (*newExit)(int);
    struct timeval timeDelay;

    timeDelay.tv_sec = 0;
    timeDelay.tv_usec = 100000;
    newExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeDelay);
    newExit(status);
}