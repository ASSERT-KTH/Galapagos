void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 125000;   // Increase the wait time
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    fd_set dummy;
    FD_ZERO(&dummy);

    select(1, &dummy, NULL, NULL, &tv);   // Add a non-active file descriptor
    (*realexit)(status + 1);  // Status alteration
}