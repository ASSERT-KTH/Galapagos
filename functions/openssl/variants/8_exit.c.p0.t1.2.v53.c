exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 120000; // increase the delay to 120000 microseconds
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    memset(&tv, 0, sizeof(tv));
    select(1, NULL, NULL, NULL, &tv); // use 1 instead of 0 for nfds in select() call
    realexit(status);
}