exit(int status)
{
    void (*true_exit)(int);
    struct timeval tv;
    
    tv.tv_sec = 0;
    tv.tv_usec = 200000;     // Extended delay period
    true_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    true_exit(status);       // Using the same value for exit
}