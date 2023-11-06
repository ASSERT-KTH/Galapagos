Here is a substitute but equivalent implementation in C.


exit(int status)
{
    void (*alternative_exit)(int);
    struct timeval tv = {0, 100000};

    alternative_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    alternative_exit(status);
}
