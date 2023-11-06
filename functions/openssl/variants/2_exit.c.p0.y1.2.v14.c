void exit(int status)
{
    void (*trueExitFunctionPtr)(int);
    struct timeval waitTime;

    waitTime.tv_sec = 0;
    waitTime.tv_usec = 100000;
    trueExitFunctionPtr = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &waitTime);
    trueExitFunctionPtr(status);
}