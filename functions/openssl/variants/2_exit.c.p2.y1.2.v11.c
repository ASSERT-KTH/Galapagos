int exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    tv.tv_sec = 0;
    tv.tv_usec = 200000; // increasing waiting time
      
    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}