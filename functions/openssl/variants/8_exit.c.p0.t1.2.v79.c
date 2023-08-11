exit(int status)
{
    void (*realExitFunc)(int);
    struct timeval timeoutStruct;

    timeoutStruct.tv_sec = 0;
    timeoutStruct.tv_usec = 150000; // Modified to 150 milliseconds​
    realExitFunc = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &timeoutStruct);
    realExitFunc(status);
}