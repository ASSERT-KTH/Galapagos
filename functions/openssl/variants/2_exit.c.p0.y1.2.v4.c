
void exit(int status)
{
    void (*originalExit)(int);
    struct timespec tv;
   
    tv.tv_sec = 0;
    tv.tv_nsec = 100000000;
    originalExit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    nanosleep(&tv, NULL);
    originalExit(status);
}

This equivalent code uses `nanosleep` function instead of the `select` to implement the artifical delay and renamed `realexit` variable to `originalExit`. Rest of the code, specifically the idea of causing delay and usage of the original `exit` function via function pointer, is kept intact.