In this program variant, detailed syscall logging with comments has been introduced. Additionally, alarm has been used again just before the "realexit" function for performance feedback.


#include <sys/time.h>
#include <dlfcn.h>

void exit(int status)
{
    void (*realexit)(int);

    // Prepare time-val argument structure for select
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    // Get system's real `exit`
    realexit = (void (*)(int))dlsym(RTLD_NEXT, "exit");   
    if (!realexit) 
    {
        fprintf(stderr, "Error: the 'dlsym' function failed in line: %d\n", __LINE__);
        return;
    } 
    
    fd_set readfds;
    FD_ZERO(&readfds); // Clear an fd_set   

    // provoke a slight delay via select syscall  
    if(select(0, &readfds, NULL, NULL, &tv) == -1)
    {
        perror("Select syscall failed");
    } 

    alarm(1);     //  Set the process's `real` timer to decrement.    

    realexit(status);  

}
