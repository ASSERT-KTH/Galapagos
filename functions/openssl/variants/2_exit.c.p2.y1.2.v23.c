void exit(int status)
{
    void (*realexit)(int status);
    struct timeval tv;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    tv.tv_sec = status == 0 ? 0 : 1; // if exit status is non-zero, wait for 1 sec
    tv.tv_usec = status == 0 ? 100000 : 500000; // if exit status is non-zero, wait for an additional half second

    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}