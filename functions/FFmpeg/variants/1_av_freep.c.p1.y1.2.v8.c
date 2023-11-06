1. Variant using pointer assignment:

void av_freep(void *arg)
{
    void **ptr = (void**)arg;
    void *val = *ptr;
    *ptr = NULL;
    av_free(val);
}

2. Variant using indirect dereferencing:

void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}


3. Variant using intptr_t to handle the void pointer arg:

#include <stdint.h>
void av_freep(void *arg)
{
    void *val;
    memcpy(&val, (void*)((intptr_t)arg), sizeof(val));
    memcpy((void*)((intptr_t)arg), &(void *){ NULL }, sizeof(val));
    av_free(val);
}


4. Variant by changing the sequence of statement:

void av_freep(void *arg)
{
    void *val = *(void **)arg;
    av_free(val);
    *(void **)arg = NULL;
}


5. Variant using macro:

#define AV_FREEP(arg) { \
    void *val = *(void **)arg; \
    *(void **)arg = NULL; \
    av_free(val); \
}

void av_freep(void *arg) 
{
    AV_FREEP(&arg);
}


Note that depending on the original meaning, behavior and calling conventions of `av_free`, and the way `arg` is constructed or the type it's pointing to, some transformations can behave different from the original function or could be erroneous/unexpected/modifying something it shouldn't. So, code transformation should be done with care, respecting the language specific details and constraints implied by the context.

Also, operator precedence and type safety issues could arise depending on how these transformed functions are called and should be kept in mind too. Specifically for the C standard, `memcpy` being used to handle pointers-to-pointers to assign NULL (void *) could be problematic in some architectures, according to the situation or compiler, leading to behavior that's undefined or wrong. Standard assignments like these using dereferencing signs, as indicated on first two variants transformations examples, tend to be most cross-architecture, safer but same time, context still should be rigorously taken into account.