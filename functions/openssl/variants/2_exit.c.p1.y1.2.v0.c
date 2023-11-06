Variant 1:

exit(int status)
{
    typedef void ExitProc(int);
    struct timeval tv = {0, 100000};

    ExitProc* realexit = (ExitProc*)dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}


Variant 2:

exit(int status)
{
    struct timeval tv;
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    select(0, 0, 0, 0, &tv);
    (*realexit)(status);
}


Variant 3:

exit(int status) {
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    struct timeval tv;
    tv.tv_sec = 0, tv.tv_usec = 100000;

    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}


Variant 4:

exit(int status) {
    void (*real_exit)(int);
    struct timeval tv = { .tv_sec = 0, .tv_usec = 100000 };

    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    real_exit(status);
}
