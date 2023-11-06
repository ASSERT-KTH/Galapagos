exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 1;  // Changing the seconds parameter to 1                                                                                                    
    tv.tv_usec = 0; // Changing the microseconds parameter to 0

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv); // Replacing zeros with NULL makes select ignore the corresponding set                                                                                                               
    realexit(status);
}