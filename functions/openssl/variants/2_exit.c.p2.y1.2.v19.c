/*
 * Version which uses usleep instead of select for a delay implementation.
 */
exit(int status)
{
    void (*realexit)(int);

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    usleep(100000);
    realexit(status);
}