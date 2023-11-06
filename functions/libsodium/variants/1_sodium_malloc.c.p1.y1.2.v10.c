Variant 1:

const size_t sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (!ptr)
        return NULL;

    memset(ptr, (int) GARBAGE_VALUE, size);
    return ptr;
}

Variant 2:

const size_t sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    
    if (ptr != NULL) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    
    return ptr;
}

Variant 3:

const size_t sodium_malloc(const size_t size)
{
    void *ptr;

    ptr = _sodium_malloc(size);

    if (ptr != NULL) 
    {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    else 
    {
        ptr = NULL;
    }

    return ptr;
}

Variant 4:

const size_t sodium_malloc(const size_t size)
{
    void *ptr=_sodium_malloc(size);

    if (ptr != NULL) 
        memset(ptr, (int) GARBAGE_VALUE, size);
  
    return ptr;
}
