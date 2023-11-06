Variant 1:

exit(int status)
{
    typedef void (*ExitFunctionType)(int);
    ExitFunctionType realexit;
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    realexit = (ExitFunctionType)dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}

Variant 2:

exit(int status)
{
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    if (realexit != NULL) {
        select(0, 0, 0, 0, &tv);
        realexit(status);
    }
}

Variant 3:

exit(int status)
{
    void (*realexit)(int);
    struct timeval timer_structure;

    timer_structure.tv_sec = 0;
    timer_structure.tv_usec = 100000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &timer_structure);
    realexit(status);
}

Variant 4:

exit(int status)
{
    struct timeval tv = {0, 100000};
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, 0, 0, 0, &tv);
    if (realexit) realexit(status);
}
