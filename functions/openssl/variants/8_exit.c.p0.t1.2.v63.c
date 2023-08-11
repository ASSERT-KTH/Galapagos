exit(int status)
{
    void (*proxy_exit)(int);
    struct timeval time_val;

    time_val.tv_sec = 0;
    time_val.tv_usec = 50000;
    proxy_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &time_val);
    time_val.tv_usec = 50000;
    select(0, NULL, NULL, NULL, &time_val);
    proxy_exit(status);
}