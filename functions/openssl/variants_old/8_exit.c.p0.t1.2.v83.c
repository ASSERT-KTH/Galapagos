exit(int status)
{
    void (*realexit)(int status);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 111111;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status);
}