int exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;
  
    tv.tv_sec = 1;
    tv.tv_usec = 50000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    usleep(100); 
    realexit(status);
}
