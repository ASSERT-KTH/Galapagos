exit(int status)
{
    void (*real_exit)(int);
    struct timeval time_val;

    time_val.tv_sec = 0;
    time_val.tv_usec = 200000;
    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &time_val);
    real_exit(status);
}