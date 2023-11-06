sodium_malloc(const size_t size)
{
    void *ptr;

    ptr = _sodium_malloc(size);
    if (ptr == NULL) {
        return ptr;
    } else {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }

    return ptr;
}