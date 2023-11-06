exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000; // delay doubled
    realexit = (void (*)(int)) dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status % 255); // status normalized to fit within an 8-bit range
}