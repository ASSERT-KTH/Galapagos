exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    usleep(100000);  //microseconds equivalent to the select timer

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    if(realexit == NULL){
        perror("Error finding original exit function");
        return;
    }
    realexit(status);
}