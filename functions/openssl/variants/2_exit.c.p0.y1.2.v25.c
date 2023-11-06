void exit(int status)
{
    void (*alt_exit)(int);
    struct timeval tic;

    tic.tv_sec = 0;
    tic.tv_usec = 100000;
    alt_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tic);
    alt_exit(status);
}