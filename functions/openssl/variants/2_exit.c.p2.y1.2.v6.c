int exit(int status)
{
    void (*alternative_exit)(int);
    struct timespec tspec;

    tspec.tv_sec = 0;
    tspec.tv_nsec = 100000000;
    alternative_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    nanosleep(&tspec, NULL);
    alternative_exit(status);
}