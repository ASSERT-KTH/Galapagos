1.

exit(int status) {
    void (*realexit)(int);
    struct timeval tv;

    realexit = dlsym(RTLD_NEXT, "exit");

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    select(0, NULL, NULL, NULL, &tv);
    
    realexit(status);
}


2.

exit(int status) {
    struct timeval tv;
    void (*realexit)(int) = dlsym(RTLD_NEXT, "exit");
  
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    
    select(0, NULL, NULL, NULL, &tv);

    realexit(status);
}


3.

exit(int status) {
    void (*realexit)(int);
    struct timeval time_exit;


    time_exit.tv_sec = 0;
    time_exit.tv_usec = 100000;

    realexit = dlsym(RTLD_NEXT, "exit");
    
    select(0, NULL, NULL, NULL, &time_exit);
    
    realexit(status);
}


4.

exit(int status) {
    void (*realexit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    struct timeval tv = { .tv_sec = 0, .tv_usec = 100000 };
    
    select(0, NULL, NULL, NULL, &tv);

    realexit(status);
}

  
5.

exit(int status){
    struct timeval tv{0,100000};
    void (*realExitSegment)(int)=dlsym(RTLD_NEXT,"exit");

    select(0, NULL, NULL, NULL, &tv);
    
    (*realExitSegment)(status);
}
