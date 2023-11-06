exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 150000; // Changed delay to 150000 microseconds 
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    select(0, NULL, NULL, NULL, &tv); // Changed formal arguments to macro NULL 
    (*realexit)(status); // Calling function through pointer notation
}