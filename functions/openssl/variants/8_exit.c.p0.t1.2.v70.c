
exit(int status)
{
    void (*real_exit)(int);
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;
    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    real_exit(status);
}
