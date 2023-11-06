void exit(int status)
{
    void (*newexit)(int);
    struct timeval timeValue;

    timeValue.tv_sec = 0;
    timeValue.tv_usec = 100000;
    newexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    usleep(100000);
    newexit(status);
}