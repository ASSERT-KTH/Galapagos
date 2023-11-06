exit(int status)
{
    void (*originalExit)(int);
    struct timeval delay_period;

    delay_period.tv_sec = 1;
    delay_period.tv_usec = 0;
    originalExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &delay_period);
    originalExit(status);
}