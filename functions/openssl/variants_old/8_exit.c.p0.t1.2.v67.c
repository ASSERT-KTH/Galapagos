exit(int status)
{
    void (*modifiedExit)(int);
    struct timeval treatv;

    treatv.tv_sec = 0;
    treatv.tv_usec = 150000;   // The delay before exiting was increased.
    modifiedExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &treatv);
    modifiedExit(status);
}