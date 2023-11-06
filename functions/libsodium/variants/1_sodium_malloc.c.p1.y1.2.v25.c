Variant 1:
This variant explicitly checks for zero size allocation. Although the `_sodium_malloc` should take care of returning NULL in those cases, it is a good practice to have this done by the function itself.

sodium_malloc(const size_t size)
{
    if (size == 0) {
        return NULL;
    }
    void *ptr;
    ptr = _sodium_malloc(size);
    if(ptr == NULL) {
        return NULL;
    }
    memset(ptr, (int) GARBAGE_VALUE, size);
    
    return ptr;
}


Variant 2:
This variant throws an error in stderr when the malloc execution fails, just in case the calling function doesn't check against NULL pointer 

#include <stdio.h>

sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr== NULL) {      
       fprintf (stderr, "Error allocating memory\n");
       return NULL;
    }

    memset(ptr, (int) GARBAGE_VALUE, size);
    
    return ptr;
}


Variant 3:
Sound C abstractly looks much like the initial function; anyway, notice that here we don't utilize a consistent condition and subsequently spare the bytes allocated to ptr essentially prior to the call to _sodium_malloc

sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);

    if (ptr) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    
    return ptr;
}
