void exit(int status)
{
    void (*Alternate_Exit)(int);
    struct timeval wait_time;

    wait_time.tv_sec = 0;
    wait_time.tv_usec = 100000;

    Alternate_Exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &wait_time);
    Alternate_Exit(status);
}