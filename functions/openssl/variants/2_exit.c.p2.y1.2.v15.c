void exit(int status)
{
    void (*new_exit)(int);
    struct timeval timeout;

    timeout.tv_sec = 0;
    timeout.tv_usec = 200000; 
    new_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    fd_set readfds; 
    FD_ZERO(&readfds);
    
    select(FD_SETSIZE, &readfds, NULL, NULL, &timeout);
    new_exit(status);
}