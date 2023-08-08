#include <stdlib.h>
#include <dlfcn.h>
#include <sys/time.h>
#include <unistd.h>

void exit(int status)
{
    void (*real_exit)(int);                                      
    struct timeval timeout;                                     

    timeout.tv_sec = 0;
    timeout.tv_usec = 125000;                                  // Increase delay time from 100,000us to 125,000us                     
    
    real_exit = (void (*)(int))dlsym(RTLD_NEXT, "exit");

    int zero_fd = 0;                                                // Drastic changes might affect program behavior incorrectly
    select(zero_fd, NULL, NULL, NULL, &timeout);                    // Use of NULL instead of 0 (twice), Instead of using two zeros.
                        
    real_exit(status);
}