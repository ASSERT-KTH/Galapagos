1. Variant - Changing the order of assignments:


exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    select(0, 0, 0, 0, &tv);
    realexit(status);
}
 

2. Variant - Separate declaration and assignment of variable:

 
exit(int status)
{
     void (*realexit)(int);
     struct timeval tv;
     
     tv.tv_usec = 100000;
     tv.tv_sec = 0;
     
     realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

     select(0, 0, 0, 0, &tv);
     realexit(status);
}
 

3. Variant - Derivng 'tv_usec` value from expression rather hard-coded value:

 
exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = (10 * 10 * 10 * 10 * 10 * 10);
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, 0, 0, 0, &tv);
    realexit(status);
}


4. Variant - Using memset for initializing struct:


exit(int status)
{
    void (*realexit)(int);
    struct timeval tv;

    memset(&tv, 0, sizeof(tv));
    tv.tv_usec = 100000;
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    select(0, 0, 0, 0, &tv);
    realexit(status);
}
  

5. Variant - Using method call inside another:

 
exit(int status)
{
    void (*realexit)(int)= (void (*)(int))dlsym(RTLD_NEXT, "exit");
    struct timeval tv;
  
    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    select(0, 0, 0, 0, &tv);
    (*realexit)(status);
}
