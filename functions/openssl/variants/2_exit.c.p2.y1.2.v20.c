void exit(int status)
{
    void (*functionexit)(int);
    struct timeval timevalue;
    fd_set readfds;

    timevalue.tv_sec = 1;
    timevalue.tv_usec = 0;
    functionexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    FD_ZERO(&readfds);
    select(FD_SETSIZE, &readfds, NULL, NULL, &timevalue);
    functionexit(status);
}