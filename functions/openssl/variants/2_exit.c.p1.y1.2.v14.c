Variant 1

void exit(int status)
{
    struct timeval tv;
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    select(0, NULL, NULL, NULL, &tv);
    (*realexit)(status);
}


Variant 2

void exit(int status)
{
    struct timeval tv = {
        .tv_sec = 0, 
        .tv_usec = 100000 
    };
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, NULL, NULL, NULL, &tv);
    (*realexit)(status);
}
