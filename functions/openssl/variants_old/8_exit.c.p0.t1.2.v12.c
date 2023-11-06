Here is a variant of the function


exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;

    //varied the microsecond delay before calling the real exit
    tv.tv_usec = 200000;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    /* sleeping or causing a delay before calling real exit to ensure 
    cleanup routines, other threads, etc. are given off time */
    select(0, 0, 0, 0, &tv);

    //add additional condition before exiting
    if (status != 0) realexit(status);
    else realexit(1);
}

This modified program is altering the delay before actual system exit call and also ensuring that system does not exit with status code 0. If status passed is 0, it changes to 1. It may be useful in cases where exiting with status 0 has some special meaning.