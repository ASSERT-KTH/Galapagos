int exit(int status) {
    void (* realexit)(int);
    struct timeval tv;
    int delay = 200000;

    tv.tv_sec = 0;
    tv.tv_usec = delay;
    realexit = (void (*) (int)) dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);
    realexit(status);
}