void exit(int status) 
{
    void (*original_exit)(int);
    struct timeval tv = { 0, 100000 }; 

    original_exit = (void(*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv);

    original_exit(status);
}