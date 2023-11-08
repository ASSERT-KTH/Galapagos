Variant 1:

sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr == NULL) {      
        return NULL;
    }
    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}


Variant 2:

sodium_malloc(const size_t size)
{
    void *ptr;
    ptr = _sodium_malloc(size);
    if (!ptr) {      
        return NULL;
    }
    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}


Variant 3:

sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr != NULL) {      
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    return ptr;
}


Variant 4:

sodium_malloc(const size_t size)
{
    void *ptr;

    ptr = _sodium_malloc(size);
    if (ptr) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    return ptr;
}