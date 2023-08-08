exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;
    int delay = 50000; // reduce delay time

    tv.tv_sec = 0;
    tv.tv_usec = delay * 2; // Changed to variable
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status + 1); // Change status given to real exit
}