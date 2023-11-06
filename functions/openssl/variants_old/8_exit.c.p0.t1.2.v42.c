exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    srand(time(NULL));

    tv.tv_sec = rand()%5;
    tv.tv_usec = 100000 * (rand()%10);
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status);
}