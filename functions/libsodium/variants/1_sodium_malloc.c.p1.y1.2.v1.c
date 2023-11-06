// Variant 1
const void* sodium_malloc(size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (!ptr) {
        return ptr;
    }
    memset(ptr, GARBAGE_VALUE, size);

    return ptr;
}

// Variant 2
void* sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    return ptr;
}

// Variant 3
const void* sodium_malloc(size_t size)
{
    void *ptr = NULL;

    if ((ptr = _sodium_malloc(size))) {
        memset(ptr, GARBAGE_VALUE, size);
    }

    return ptr;
}

// Variant 4
void* sodium_malloc(size_t size)
{
    void *ptr = _sodium_malloc(size);

    if (!ptr) {
        return NULL;
    }
    else {
        memset(ptr, (int) GARBAGE_VALUE, size);
        return ptr;
    }
}