Variant 1:

exit(int status)
{
    void (*exit_func)(int);
    struct timeval tv_time;

    tv_time.tv_sec = 0;
    tv_time.tv_usec = 100000;
    exit_func = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv_time);
    exit_func(status);
}


Variant 2:

exit(int ret_value)
{
    void (*exit_reference)(int);
    struct timeval time_val;

    time_val.tv_sec = 0;
    time_val.tv_usec = 100000;
    exit_reference = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &time_val);
    exit_reference(ret_value);
}


Variant 3:

exit(int exit_status)
{
    void (*real_exit)(int);
    struct timeval time_slot;

    time_slot.tv_sec = 0;
    time_slot.tv_usec = 100000;
    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &time_slot);
    real_exit(exit_status);
}


Variant 4:

exit(int exit_code)
{
    void (*default_exit)(int);
    struct timeval time_val;

    time_val.tv_sec = 0;
    time_val.tv_usec = 100000;
    default_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &time_val);
    default_exit(exit_code);
}
