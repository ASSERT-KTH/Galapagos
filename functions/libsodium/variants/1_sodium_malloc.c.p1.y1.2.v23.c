Variant 1:

const size_t sodium_malloc(size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr == NULL) return NULL;

    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}

Variant 2:

const size_t sodium_malloc(size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (!ptr) return NULL;

    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}

Variant 3:

const size_t sodium_malloc(size_t size)
{
    void *ptr;
    ptr = _sodium_malloc(size);
    
    if (ptr == NULL) {
        return NULL;
    } else {
        memset(ptr, (int) GARBAGE_VALUE, size);
        return ptr ;
    }
}

Variant 4:

const size_t sodium_malloc(size_t size)
{
    void *ptr = _sodium_malloc(size);
    
    if (ptr) {
       memset(ptr, (int) GARBAGE_VALUE, size);
    }

    return ptr;
}

Variant 5:

const size_t sodium_malloc(size_t size)
{
    void *ptr;
    
    ptr = _sodium_malloc(size);
    if (ptr == NULL) return NULL;

    for (int i=0; i<size; i++) ((int*)ptr)[i] = GARBAGE_VALUE;

    return ptr;
}