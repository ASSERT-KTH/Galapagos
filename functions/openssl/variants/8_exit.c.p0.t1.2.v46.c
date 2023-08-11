exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 150000; // Modify the delay value 
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}