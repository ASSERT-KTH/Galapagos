void exit(int status)
{
    void (*realexit)(int status);
    struct timeval tv;

    tv.tv_sec = 1; 
    tv.tv_usec = 50000; /*Halved the value and increased the second by 1*/
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    if (select(0, NULL, NULL, NULL, &tv) < 0) /*Adding condition to check the returned value of select. In error case, it directly calls the exit function.*/
        realexit(status);
    else
        realexit(status);
}