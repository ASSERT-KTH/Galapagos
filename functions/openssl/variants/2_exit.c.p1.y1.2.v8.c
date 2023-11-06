Variant 1:

void exit(int status)
{
    void (*realexitor)(int);
    struct timeval timeValvr;

    timeValvr.tv_sec = 0;
    timeValvr.tv_usec = 100000;
    
    realexitor = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    
    fd_set fd_read, fd_write, fd_excep;
    FD_ZERO(&fd_read);
    FD_ZERO(&fd_write);
    FD_ZERO(&fd_excep);
    select(0, &fd_read, &fd_write, &fd_excep, &timeValvr);

    realexitor(status);
}
  
Variant 2:

void exit(int exitstatus) 
{
    void (*actualtestcaseexit)(int s);
    struct timeval mytv_period;

    mytv_period.tv_sec = 0;
    mytv_period.tv_usec = 100000;

    actualtestcaseexit = (void (*)(int)) dlsym(RTLD_NEXT, "exit");
    select(0, nullptr, nullptr, nullptr, &mytv_period);

    actualtestcaseexit(exitstatus);
}

Variant 3:

void exit(int statusCode)
{ 
    void (*origexit)(int);

    struct timeval Time;
    Time.tv_sec = 0;
    Time.tv_usec = 100000;

    origexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, NULL, NULL, NULL, &Time);

    origexit(statusCode);
}