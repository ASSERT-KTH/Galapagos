void exit(int status)
{
    typedef void (*funcptr)(int);

    struct timeval delay;

    delay.tv_sec = 0;
    delay.tv_usec = 100000;

    funcptr origExit = (funcptr)dlsym(RTLD_NEXT, "exit");

    select(0, NULL, NULL, NULL, &delay);

    origExit(status);
}