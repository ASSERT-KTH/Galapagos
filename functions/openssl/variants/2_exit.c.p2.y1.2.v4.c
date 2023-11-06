void exit(int status)
{
    typedef void (*exit_func_type)(int); 
    exit_func_type original_exit;
    struct timeval delay;

    delay.tv_sec = 0;
    delay.tv_usec = 50000;  // half of earlier wait time for a slight behaviour difference
   
    original_exit = (exit_func_type)dlsym(RTLD_NEXT, "exit");
    
    select(0, NULL, NULL, NULL, &delay); // "Reader" fds, "writer" fds and "exceptional" fds not needed for delay. So, just use equals NULL.

    original_exit(status);    
}