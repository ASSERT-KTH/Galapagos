Here's a variant program where I introduced error checking functionality. The generic behavior when passing a NULL pointer to the free_pointer function remains the same but an additional operation of printing an error message to stderr is also carried out which the original function did not consider.


#include <stdio.h>

void av_free(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Error: NULL pointer can not be freed\n");
        return;
    }
      
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}
 

Remember that this will only add print functionality when an error is encountered, it does not affect the performance of the original function.