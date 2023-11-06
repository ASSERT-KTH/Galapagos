exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000; // Increase the delay time
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status * 2); // Transform the exit status before passing 
}