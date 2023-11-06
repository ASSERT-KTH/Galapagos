void exit(int status)
{
    void (*alternateexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    alternateexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    fd_set emptyset;
    FD_ZERO(&emptyset);
    select(FD_SETSIZE, &emptyset, &emptyset, &emptyset, &tv);
    alternateexit(status);
}