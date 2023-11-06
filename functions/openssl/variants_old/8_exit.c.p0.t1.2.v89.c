int exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 50000;    // Halve the delay time
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    // perform some operation before calling exit
    status += 1;   // Increment the status before exiting
    
    select(0, 0, 0, 0, &tv); 
    realexit(status);   // Call the real exit function with amended status
}