int exit(int status)
{
    void (*real_exit_function)(int);
    struct timeval timer;

    timer.tv_sec = 0;
    timer.tv_usec = 200000; // delay for 200 microseconds
    real_exit_function = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timer);
    real_exit_function(status);
}