void exit(int status)
{
    void (*reattachedexit)(int);
    struct timeval time_value;
    struct timezone time_zone;

    time_value.tv_sec = 0;
    time_value.tv_usec = 200000; /* Microseconds (1s = 10^6) */
    reattachedexit = (void (*)(int)) dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &time_value);
    reattachedexit(status);
}