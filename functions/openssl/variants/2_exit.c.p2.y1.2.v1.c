void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    fd_set rfds;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    select(1, &rfds, NULL, NULL, &tv);

    realexit(status);
}