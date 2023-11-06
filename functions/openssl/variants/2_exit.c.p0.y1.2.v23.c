void exit(int status)
{
    void (*exit_proc)(int);
    struct timeval wait_time = {0, 100000};

    exit_proc = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &wait_time);
    exit_proc(status);
}