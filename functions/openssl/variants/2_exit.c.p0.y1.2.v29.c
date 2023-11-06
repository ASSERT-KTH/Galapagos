void exit(int status)
{
    void (*alternativeExit)(int);
    struct timeval timeValue;

    timeValue.tv_sec = 0;
    timeValue.tv_usec = 100000;
    alternativeExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timeValue);
    alternativeExit(status);
}