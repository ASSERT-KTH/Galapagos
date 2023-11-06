void exit(int status)
{
    void (*newexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    newexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    newexit(status);
}