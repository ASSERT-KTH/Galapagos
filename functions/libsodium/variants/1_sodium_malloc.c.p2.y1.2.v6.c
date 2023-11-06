Here's a program variant that uses the calloc function for memory allocation and initial set to 0 before the memory is set to the GARBAGE_VAL. It slightly differs from the original program, but still maintains its initial functionality:

const size_t sodium_malloc(const size_t size)
{
    void *ptr = calloc(1, size);

    if (!ptr) {
        return NULL;
    }

    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}