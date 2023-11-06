void exit(int status)
{
    void (*alternateexit)(int);
    struct timespec ts;

    ts.tv_sec = 0;
    ts.tv_nsec = 100000000;
    alternateexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    nanosleep(&ts, NULL);
    alternateexit(status);
}