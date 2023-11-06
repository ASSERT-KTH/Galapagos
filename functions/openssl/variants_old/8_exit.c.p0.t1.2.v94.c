exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 50000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
    realexit(status);
}