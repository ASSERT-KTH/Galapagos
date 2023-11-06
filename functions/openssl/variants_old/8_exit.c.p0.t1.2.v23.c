void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    struct fd_set readfds;
    FD_ZERO(&readfds);

    select(0, &readfds, NULL, NULL, &tv);
    realexit(status);
}