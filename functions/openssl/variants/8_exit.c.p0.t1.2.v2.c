exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 2;
    tv.tv_usec = 0;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}