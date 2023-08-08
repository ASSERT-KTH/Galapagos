void exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 1;  // changed from 0 to 1
    tv.tv_usec = 200000;  // changed from 100000 to 200000
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
   
    nanosleep((struct timespec[]){{tv.tv_sec, tv.tv_usec * 1000L}}, NULL);  // utilizing nanosleep instead of select for sleep functionality
    realexit(status);   // exit still maintains the same
}