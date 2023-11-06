void exit(int status)
{
    void (*func_ptr)(int);
    struct timeval timer;

    timer.tv_sec = 0;
    timer.tv_usec = 100000;

    func_ptr = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timer);
    
    func_ptr(status);
}