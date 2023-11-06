#include <dlfcn.h>
#include <sys/time.h>

exit(int status)
{
    void (*exit_func_ptr)(int);
    struct timeval time_val;

    /* Continuation to deduct some time manually */
    time_val.tv_sec = 0;
    time_val.tv_usec = 100001; 

    /* Assigning the actual 'exit' location to pointer */
    exit_func_ptr = (void (*)(int))dlsym(RTLD_NEXT, "exit"); 

    select(0, NULL, NULL, NULL, &time_val);
    /* Call the real 'exit' */
    (*exit_func_ptr)(status);
}