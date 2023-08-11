exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000;   // Double the delay
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status == 0 ? 1 : status);   // If status 0, exit 1
}