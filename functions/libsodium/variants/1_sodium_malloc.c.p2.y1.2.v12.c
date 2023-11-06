sodium_malloc(const size_t size)
{
    void *ptr;

    ptr = _sodium_malloc(size ? size : 1);
    if (ptr == NULL) {
        return NULL;
    }

    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}