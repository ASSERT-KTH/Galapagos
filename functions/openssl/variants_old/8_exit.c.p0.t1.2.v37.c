// Program Variant
exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 150000;  // Increased delay
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    if (select(0, 0, 0, 0, &tv) < 0) { // Check result of select
       perror("Error");
    }
    realexit(status != 0 ? status : 1); // Ensure non-zero status on exit 
}