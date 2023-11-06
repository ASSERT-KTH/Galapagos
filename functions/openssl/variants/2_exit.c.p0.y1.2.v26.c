void exit(int status)
{
    void (*exit_func)(int);
    struct timeval time_val;

    time_val.tv_sec = 0;
    time_val.tv_usec = 100000;

    exit_func = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, NULL, NULL, NULL, &time_val);

    exit_func(status);
}