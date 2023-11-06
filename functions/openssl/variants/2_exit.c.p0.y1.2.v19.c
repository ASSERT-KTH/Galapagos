void exit(int status)
{
    void (*actual_exit)(int);
    struct timeval delay_time;

    delay_time.tv_sec = 0;
    delay_time.tv_usec = 100000;

    actual_exit = reinterpret_cast<void (*)(int)>(dlsym(RTLD_NEXT, "exit"));

    select(0, nullptr, nullptr, nullptr, &delay_time);

    actual_exit(status);
}