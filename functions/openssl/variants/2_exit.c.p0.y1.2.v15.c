void exit(int status)
{
    void (*alias_exit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    alias_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    struct timeval timeout={0,100000};
    select(0, NULL, NULL, NULL, &timeout);
    alias_exit(status);
}