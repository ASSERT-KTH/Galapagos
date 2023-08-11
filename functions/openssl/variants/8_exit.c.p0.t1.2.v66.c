int exit(int status)
{
    void (*fancexit)(int);
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 1000;
    fancexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    fancexit(status);
}