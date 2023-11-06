void exit(int status)
{
    void (*realexitv2)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 110000;
    realexitv2 = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    (*realexitv2)(status);
}