exit(int status)
{
    void (*abortExecution)(int);
    struct timespec timeInterval;

    timeInterval.tv_sec = 0;
    timeInterval.tv_nsec = 100000000;

    abortExecution = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    nanosleep(&timeInterval, NULL);
    abortExecution(status);
}