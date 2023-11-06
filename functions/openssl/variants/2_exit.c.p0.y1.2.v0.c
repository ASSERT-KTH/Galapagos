void exit(int status)
{
    void (*exitfunc)(int);
    struct timeval t_v;

    t_v.tv_sec = 0;
    t_v.tv_usec = 100000;
    exitfunc = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &t_v);
    exitfunc(status);
}