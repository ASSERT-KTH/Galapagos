Variant 1: simply switching the order of code without affecting overall functionality

exit(int status) {
    struct timeval tv;
    void (*realexit)(int);

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    select(0, 0, 0, 0, &tv);
    
    realexit(status);
}


Variant 2: change variable names as a different alternative that still maintains functionality

exit(int exit_code) {
    struct timeval sleep_time;
    void (*actual_exit)(int);

    sleep_time.tv_sec = 0;
    sleep_time.tv_usec = 100000;
    actual_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
 
    select(0, 0, 0, 0, &sleep_time);
    actual_exit(exit_code);
}


Variant 3: change structure to remove the explicit usage of temporary variable

exit(int status) {
    struct timeval tv = { 0, 100000 };
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, 0, 0, 0, &tv);
    realexit(status);
}
