void exit(int status)
{
    void (*realExitFunc)(int);
    struct timeval timeInfo;

    timeInfo.tv_sec = 1;
    timeInfo.tv_usec = 0;
    realExitFunc = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeInfo);
    realExitFunc(status);
}