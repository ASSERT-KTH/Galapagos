exit(int status)
{
    void (*newExitFunction)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000; // Increasing the wait time
    newExitFunction = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    newExitFunction(status);
}