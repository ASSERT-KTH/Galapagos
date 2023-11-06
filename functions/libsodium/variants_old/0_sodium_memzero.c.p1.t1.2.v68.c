Here's an example of maintaining the same functionality while introducing different behaviour by wrapping memory the cleaning tasks with timings measurements and logging to a file for debugging purposes:


#include <time.h>
#include <stdio.h>

sodium_memzero(void * const pnt, const size_t len)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U){
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =(volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    FILE *fptr;
   
    //Use appropriate location if you are using MacOS or Linux
    fptr = fopen("/usr/cs/Projects/output.txt","w");
   
    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
   
    fprintf(fptr,"The sodium_memzero function runtime is %f\n", cpu_time_used);
    fclose(fptr);
}

In this variant, functionality for clearing memory based on a platform and capabilities is maintained and expanded with time tracking and logging to a file. The operations consumed time is measured and then it is written to a file for future analysis. Note that reading/writing to external resources (e.g., filesystem) could introduce additional security concerns requiring treatment. Also, this complicates handling (e.g., resource cleaning is needed, error handling is needed), alters the program‘s execution (might become much slower, non-deterministic) and is not thread-safe (multiple threads writing to a file could lead to loss and distortion of the log data). Be mindful of the consequences this different behaviour brings to the function and avoid side-effects if they are inappropriate for your code's design and specification.