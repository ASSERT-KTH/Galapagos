void exit(int status)
{
    void (*modifiedexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    modifiedexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    modifiedexit(status);
}