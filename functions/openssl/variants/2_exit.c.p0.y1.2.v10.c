void exit(int status)
{
    void (*real_exit_func)(int);
    struct timeval time_val;

    time_val.tv_sec = 0;
    time_val.tv_usec = 100000;
    real_exit_func = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &time_val);
    real_exit_func(status);
}