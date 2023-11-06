The reference implementation of this function uses many conditional directives to choose the best way to erase the content of a block of memory depending on the result at compile-time of feature checks. As asked to modify the behavior, these could be replaced with different function or optimization different than the listed ones. Here's one possible modification, using `calloc()`, readily available in the standard C library:


#include <stdlib.h>

void sodium_memzero(void * const pnt, const size_t len)
{
    void * new_space = calloc(1, len);

    if (new_space != NULL) 
    {
        memcpy(pnt, new_space, len);
        free(new_space);
         
#ifdef HAVE_INLINE_ASM
        __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
#endif
    }
    else 
    {
        volatile unsigned char *volatile pnt_ =
            (volatile unsigned char *volatile) pnt;
        size_t i = (size_t) 0U;

        while (i < len) 
        {
            pnt_[i++] = 0U;
        }
    }
}

Essentially, it first tries to allocate a zero-initialized block of memory of the same size using `calloc()`, and then `memcpy()` it to the original block, which results in erasing the original content. If `calloc()` fails and returns NULL, it defaults to the manual memset process like the original implementation. Note that `memcpy()` or replacing blocks of memory may not always amount to exactly the same underlying operation on some platforms (due to stuff like cache behaviour, parallelism). Also, `memset_s`, `SecureZeroMemory` and similar functions are preferred as they typically assure immediate erasure, preventing certain optimizations or repercussions.
