exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    // Reduced the delay time before exit by factor of 2 
    tv.tv_sec = 0;
    tv.tv_usec = 50000;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    // Adding a null statement 
    // which doesn't modify behavior or functionality of the program
    {}

    select(0, 0, 0, 0, &tv);
    realexit(status + 5); // Change status that was in the program
}