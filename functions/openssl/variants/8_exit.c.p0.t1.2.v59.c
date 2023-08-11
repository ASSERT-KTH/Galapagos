exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000;    // Changed sleep time from 100000 µseconds to 200000 µseconds
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, 0, NULL, &tv);
    realexit(status);
}