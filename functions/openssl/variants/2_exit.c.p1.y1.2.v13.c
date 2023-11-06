// Variant 1
exit(int status)
{
    void (*atexit_call)(int);
    struct timeval select_time;
    select_time.tv_sec = 0;
    select_time.tv_usec = 100000;

    atexit_call = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &select_time);
    atexit_call(status);
}

// Variant 2
exit(int exit_status)
{
    void (*exit_func)(int);
    struct timeval select_tv;
    
    exit_func = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select_tv.tv_sec = 0;  
    select_tv.tv_usec = 100000; 
    select(0, 0, 0, 0, &select_tv);
    exit_func(exit_status);
}

// Variant 3
exit(int terminating_value)
{
    void (*exit_occur)(int);
    struct timeval tv_exit;
    
    tv_exit.tv_sec = 0;  
    tv_exit.tv_usec = 100000; 
    
    exit_occur = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv_exit); 
    exit_occur(terminating_value);
}

// Variant 4
exit(int exit_status_code)
{
    void (*terminate)(int);
    struct timeval time_before_exit;

    
    terminate = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    time_before_exit.tv_sec = 0;  
    time_before_exit.tv_usec = 100000; 
    
    select(0, NULL, NULL, NULL, &time_before_exit); 
    terminate(exit_status_code);
}