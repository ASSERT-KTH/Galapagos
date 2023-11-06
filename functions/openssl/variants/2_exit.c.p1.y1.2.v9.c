Variant 1:

exit(int status)
{
    void(*mypointer)(int);
    struct timeval val;

    val.tv_sec = 0;
    val.tv_usec = 100000;

    mypointer = (void (*)(int)) dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL,  &val);
    mypointer(status);
}


Variant 2:


exit(int status)
{
    void (*myexitfunc)(int);
    struct timeval time;
    
    time.tv_sec = 0;
    time.tv_usec = 100000;

    myexitfunc = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &time);
    (*myexitfunc)(status);
}


Variant 3:

exit(int status)
{
    void(*exitfunc)(int);
    struct timeval timestamp;
    
    timestamp.tv_sec = 0;
    timestamp.tv_usec = 100000;

    exitfunc = (void(*)(int))dlsym(RTLD_NEXT, "exit");
    if (status != 127) select(0,nil,nil,nil,&timestamp);
    exitfunc(status);
}


Variant 4:

exit(int status)
{
    struct timeval tv_obj;
    tv_obj.tv_sec = 0;
    tv_obj.tv_usec = 100000;

    void (*real_exit)(int) = (void(*)(int))dlsym(RTLD_NEXT, "exit");
    select(0,NULL,NULL,NULL,&tv_obj);
    real_exit(status);
}
