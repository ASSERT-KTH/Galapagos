const size_t sodium_malloc(const size_t size)
{
    void *ptr;

    ptr = _sodium_malloc(size);

    if (!ptr) {
        return NULL;
    }
    else {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }

    return (size_t)ptr;
}