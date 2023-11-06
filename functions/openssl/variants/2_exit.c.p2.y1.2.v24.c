// Variant implementation of exit function in C
exit(int status)
{
    void (*exitfunc)(int);
    struct timeval delay;

    delay.tv_sec = 0;
    delay.tv_usec = 100000;
    exitfunc = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    fd_set set; // will be zero due to being local without a preceding FD_ZERO, this should essentially perform the delay of the original program
    select(1, &set, NULL, NULL, &delay);
    exitfunc(status);
}