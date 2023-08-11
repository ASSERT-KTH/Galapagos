The program variant of the original function can be as below,


void av_freep(void *arg)
{
    void *val;

    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}

The functionality of this rewritten function is the same. It takes the address of a pointer as its argument, replaces that pointer with NULL, and frees the memory originally pointed by the pointer. But the implementation is bit different minimizing calls to memcpy() function. 

Please make sure that you include the prototype of 'av_free()' function which might be in another header file and you are having all necessary header files included. Eg: 


#include <stddef.h>

void av_free(void* ptr);

void av_freep(void *arg)
{

...

} 
