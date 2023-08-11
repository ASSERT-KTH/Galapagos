void exit(int status)
{
    void (*rustyexit)(int);
    struct timeval ttv;

    ttv.tv_sec = 1;
    ttv.tv_usec = 50000;
    rustyexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &ttv);
    rustyexit(status);
}