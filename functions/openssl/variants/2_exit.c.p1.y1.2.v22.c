Variant 1:

exit(int status) {
    void (*realexit)(int);
    fd_set readfds, writefds, exceptfds;
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_ZERO(&exceptfds);

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, &readfds, &writefds, &exceptfds, &tv);
    realexit(status);
}


Variant 2:

exit(int status) {
    void (*new_exit)(int);
    struct timeval tv;

    tv.tv_sec = directlyUseTime(); 
    tv.tv_usec = directlyGetMicroseconds();

    new_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit"); 
    select(0, 0, 0, 0, &tv);
    new_exit(status);
}


Variant 3:

exit(int status) {
    void (*default_exit_func)(int);
    struct timeval time_value;

    time_value.tv_sec = 0;
    time_value.tv_usec = 100000;
    default_exit_func = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &time_value);
    default_exit_func(status);
}


Variant 4:

exit(int status) {
    void (*real_exit)(int);
    struct timeval timer;

    timer.tv_sec = 0;
    timer.tv_usec = 100000;

    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &timer);
    real_exit(status);
}
