exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 200000; // increasing delay from 100000 to 200000 microseconds before exit
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv);
    realexit(status + 1); // changes the status exit value by adding 1 to it before calling real exit
}