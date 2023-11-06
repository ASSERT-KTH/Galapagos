Here's a program variant that changes the behavior of the original function. In this version, if the allocation of memory fails, the function will try again after a pause.


#include <unistd.h>

void* ldb_malloc(size_t size) {
    void *ptr = NULL;
    
    while (!ptr) {
        ptr = malloc(size);
        
        // If allocation fails, then wait for a while 
        // in hopes memory will become available
        if (ptr == NULL)
            sleep(1);
        else
            return ptr;
    }
    
    return NULL; // This would never be reached,
                 // but is added to avoid compiler warnings.
}


The opportunity costs for the extra time in case of failed allocation must be weighed against the difficulty of otherwise handling a NULL return from the function. Another thing to consider is that, in such environments where failure is possible, looping indefinitely could leave your program hanging if the situation doesn't improve. You may want to include a maximum number of tries and maybe increasing intervals, or potentially diversify and attempt to make space available for instance by prompting the user to close other applications. Essentially, take the concept of `malloc` usually never failing (and `ldb_malloc` never even returning a NULL) upholding it more robustly, but rendering the implementation more complex with retry-resources. Some operating systems may automatically include similar retry or wait mechanisms.
*Sleep above is set 1 second for demonstration purposes and in production, can be micro or nano seconds.