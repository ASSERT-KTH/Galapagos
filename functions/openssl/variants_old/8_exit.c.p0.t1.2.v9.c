exit(int status)
{
    void (*modified_exit)(int);
    struct timeval tv;

    modified_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    gettimeofday(&tv, NULL);
    tv.tv_sec += 1;
    select(0, NULL, NULL, NULL, &tv);
    
    modified_exit(status);
}