exit(int status)
{
    void (*real_exit)(int);
    printf("Exiting with status: %d\n", status); //Added status logging
    struct timeval tv1;

    tv1.tv_sec = 0;
    tv1.tv_usec = 10000; //Reduced waiting time
    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, 0, 0, 0, &tv1);
    real_exit(status);
}