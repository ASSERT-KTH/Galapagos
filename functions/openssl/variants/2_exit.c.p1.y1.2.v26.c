Variant 1:

exit(int status)
{
    typedef void (*exit_type)(int);
    struct timeval tv;
    exit_type real_exit;

    tv.tv_sec = 1;
    tv.tv_usec = 0;
    real_exit = (exit_type)dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    real_exit(status);
}


Variant 2:

exit(int status)
{
    void (*real_exit)(int);
    struct timeval tv = { .tv_sec = 0, .tv_usec = 100000 };

    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    real_exit(status);
}


Variant 3:

exit(int status)
{
    void (*exit_func)(int);
    struct timeval wait_time;

    wait_time.tv_sec = 0;
    wait_time.tv_usec = 1000 * 100;
    exit_func = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &wait_time);
    exit_func(status);
}
