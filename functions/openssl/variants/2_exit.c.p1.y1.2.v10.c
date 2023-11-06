1. Changing local variable names:


exit(int exit_status)
{
    void (*exit_func_pointer)(int);
    struct timeval tv_timer;

    tv_timer.tv_sec = 0;
    tv_timer.tv_usec = 100000;
    exit_func_pointer = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv_timer);
    exit_func_pointer(exit_status);
}


2. Switching declaration and assignment location:


exit(int s)
{
    struct timeval t_v;
    void (*re_exit)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    t_v.tv_sec = 0;
    t_v.tv_usec = 100000;
    select(0, 0, 0, 0, &t_v);
    re_exit(s);
}


3. Using timespace macros for timeval structure data:


exit(int status)
{
    void (*real_exit_func_pointer)(int);
    struct timeval time_value;

    time_value.tv_sec = TIME_ZERO;
    time_value.tv_usec = TIME_DELAY;
    real_exit_func_pointer = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(NULL, NULL, NULL, NULL, &time_value);
    real_exit_func_pointer(status);
}

  
  Please note that the values for TIME_ZERO and TIME_DELAY macros must be defined in header.
  
  
  #define  TIME_ZERO   0
  #define TIME_DELAY  100000
  
  
4. Direct application of timeval structure data:


exit(int status)
{
    void (*exit_pointer)(int);
    exit_pointer = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    struct timeval t_v = { .tv_sec = 0, .tv_usec = 100000 };
    select(0, 0, 0, 0, &t_v);
    
    exit_pointer(status);
}
