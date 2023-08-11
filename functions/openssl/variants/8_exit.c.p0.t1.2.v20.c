exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000;  // Change the value from 100000 to 200000
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status+1);  // Change the exit status value
}