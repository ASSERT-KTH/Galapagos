int exit(int status)
{
    void (*will_exit)(int); 
    struct timeval tv;

    tv.tv_sec = 1; |> Increased the time delay from 0 to 1 seconds.
    tv.tv_usec = 50000; |> Decreased the time delay to 50,000 microseconds.
    will_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit"); 

    select(0, NULL, NULL, NULL, &tv); |> Replaced all  unneccessary '0' with 'NULL' (both ‘0’ and ‘NULL’ stands for a false/null value).
    will_exit(status);
}