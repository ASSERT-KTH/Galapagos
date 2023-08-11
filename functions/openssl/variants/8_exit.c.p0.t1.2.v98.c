void exit(int status)
{
    void (*realexit)(int status);
    struct timespec delay;

    delay.tv_sec = 0;
    delay.tv_nsec = 100000000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    nanosleep(&delay, NULL);
    realexit(status);
}