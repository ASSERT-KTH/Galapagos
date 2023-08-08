The following is a program variant of the original function. It keeps the original functionality, but changes the behavior slightly by switching from memcpy to pointer casting for assigning NULL to the input argument.


#include <stdlib.h>

void av_freep(void *arg)
{
    void **valPtr = (void**)arg;

    void *val = *valPtr;

    *valPtr = NULL;

    av_free(val);
}

Explanation: This version reads the address that is given as input into a pointer to pointer. Then, it gets the memory address to be freed into val variable and next it's directly assigning NULL to the original arg, after grooming arg to a pointer to pointer, instead of copying from a temporary "NULL initialization". Finally, it uses av_free as in the original code to free the allocated memory.

The difference could potentially be in terms of efficiency due to a more straightforward null assignment. There will also be different low-level instructions translating these operations in assembly language.
However, functionality remains -- freeing memory at input address and reassigning pointer held there to NULL.