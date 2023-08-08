exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 1; // Add 1 second delay
    tv.tv_usec = 0; // Reset microseconds
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv); // Use NULL instead of 0
    realexit(status);
}