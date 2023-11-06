Option 1:


const size_t sodium_malloc(size_t size)
{
    void *ptr = _sodium_malloc(size);

    if (!ptr) {
        return NULL;
    }
    memset(ptr, (int) GARBAGE_VALUE, size);

    return (size_t) ptr;
}


Option 2:


const size_t sodium_malloc(size_t size)
{
    void *ptr = NULL;
    ptr = _sodium_malloc(size);

    if (ptr == NULL) {
        return 0;
    } else {
        memset(ptr, (int) GARBAGE_VALUE, size);
        return (size_t) ptr;
    }
}


Option 3:


const size_t sodium_malloc(size_t size)
{
    void *ptr = _sodium_malloc(size);
    
    if (ptr != NULL) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
 
    return (size_t) ptr;
}
