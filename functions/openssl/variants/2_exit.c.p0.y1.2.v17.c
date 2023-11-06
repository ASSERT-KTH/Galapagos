void exit(int status)
{
    void (*proxy_exit)(int);
    struct timeval tvs;

    tvs.tv_sec = 0;
    tvs.tv_usec = 100000;
    proxy_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tvs);
    proxy_exit(status);
}