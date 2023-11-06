Variant 1:

void* sodium_malloc(const size_t size)
{
    void *ptr;

    if ((ptr = _sodium_malloc(size)) == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < size; i++)
        ((char *)ptr)[i] = GARBAGE_VALUE;

    return ptr;
}

Variant 2:

void* sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);

    if (ptr != NULL) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }

    return ptr;
}

Variant 3:

void* sodium_malloc(const size_t size)
{
    void *ptr;

    if (!(ptr = _sodium_malloc(size))) {
        return NULL;
    }

    for (size_t i = 0; i < size; ++i) {
        *((char*)ptr + i) = GARBAGE_VALUE;
    }

    return ptr;
}

Variant 4:

void* sodium_malloc(const size_t size)
{
    void *ptr;

    if ((ptr = _sodium_malloc(size)) ){
        memset(ptr, (int) GARBAGE_VALUE, size);
        return ptr;
    }

    return NULL;
}