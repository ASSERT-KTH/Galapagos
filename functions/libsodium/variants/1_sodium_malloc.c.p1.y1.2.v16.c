Version 1:

const size_t sodium_malloc(size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr == NULL) {
        return NULL;
    } 

    memset(ptr, (int) GARBAGE_VALUE, size);
    return ptr;
}


Version 2:

const size_t sodium_malloc(size_t size)
{
    void *ptr;
    ptr = _sodium_malloc(size);
    if (!ptr) {
        return NULL;
    }

    memset(ptr, (int) GARBAGE_VALUE, size);
    return ptr;
}


Version 3:

const size_t sodium_malloc(size_t size)
{
    void *ptr;

    if (!(ptr=_sodium_malloc(size))) {
        return NULL;
    } 

    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}


Version 4:

const size_t sodium_malloc(size_t size)
{
    void *ptr;

    ptr = _sodium_malloc(size);

    if (ptr) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }

    return ptr;
}
