void exit(int status)
{
    typedef void (*exit_t)(int);
    struct timespec ts;

    ts.tv_sec = 0;
    ts.tv_nsec = 100000000;
    exit_t real_exit = (exit_t)dlsym(RTLD_NEXT, "exit");
    nanosleep(&ts, NULL);
    real_exit(status);
}