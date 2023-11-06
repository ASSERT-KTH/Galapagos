Variant 1:

exit(int status) 
{
    void (*real_exit_fn)(int);
    struct timeval exit_delay_tv;

    exit_delay_tv.tv_sec = 0;
    exit_delay_tv.tv_usec = 100000;
    
    real_exit_fn = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    select(0, NULL, NULL, NULL, &exit_delay_tv);

    real_exit_fn(status);
}


Variant 2:

exit(int stat) 
{
    void (*exit_function_ptr)(int);
    struct timeval delay_struct;
        
    delay_struct.tv_sec = 0;
    delay_struct.tv_usec = 100000;
    
    exit_function_ptr = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    select(0, NULL, NULL, NULL, &delay_struct);
    
    (*exit_function_ptr)(stat);
}


Variant 3:

exit(int exit_code) 
{
    void (*real_exit)(int);
    struct timeval exit_delay;

    exit_delay.tv_sec = 0;
    exit_delay.tv_usec = 100000;

    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, 0, 0, 0, &exit_delay);

    real_exit(exit_code);
}


Variant 4:

exit(int ext_sts) 
{
    struct timeval t;

    t.tv_sec = 0;
    t.tv_usec = 100000;
    
    void (*ex_func)(int) = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    select(0, 0, 0, 0, &t);
    
    ex_func(ext_sts);
}
