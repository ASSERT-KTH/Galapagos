Variant 1:

void* sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);

    if (ptr == NULL) {
        return NULL;
    }
    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}
 

Variant 2:

void* sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);

    if (!ptr) {
        return NULL;
    }

    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}


Variant 3:

void* sodium_malloc(const size_t size)
{
    void *ptr;

    if (size)
    {
        ptr = _sodium_malloc(size);
        
        if (ptr) {
            memset(ptr, (int)GARBAGE_VALUE, size);
            return ptr;
        }
    }

    return NULL;
}


Variant 4:

void* sodium_malloc(const size_t size)
{
    void *ptr;

    if ( !size || !(ptr = _sodium_malloc(size)) ) {
        return NULL;
    }
    
    memset(ptr, (int)GARBAGE_VALUE, size);
    return ptr;
}
