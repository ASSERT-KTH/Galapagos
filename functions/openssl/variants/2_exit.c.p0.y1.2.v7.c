void exit(int status)
{
    void (*real_exit)(int) = NULL;
    struct timeval tv = {0};

    tv.tv_usec = 100000;
    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    fd_set dummy;
    FD_ZERO(&dummy);
    select(0, &dummy, &dummy, &dummy, &tv);

    real_exit(status);
}