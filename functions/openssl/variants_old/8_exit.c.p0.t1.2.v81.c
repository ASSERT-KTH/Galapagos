#include <dlfcn.h>
#include <sys/time.h>
#include <stdlib.h>

void exit(int status)
{
   void (*realexit)(int);
   struct timeval tv;

   tv.tv_sec = 1; //altered time here 
   tv.tv_usec = 50000; //also here
   realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");
   select(0, NULL, NULL, NULL, &tv); //Changed 0s to NULLs
   realexit(status);
}