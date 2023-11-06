sodium_malloc(const size_t size)
{
    if (size == 0)
        return NULL;

    void *ptr;

    ptr = _sodium_malloc(size);

    if (!ptr) {
        return NULL;
    }

    for (size_t i = 0; i < size; i++)
        ((char*)ptr)[i] = (char)GARBAGE_VALUE;

    return ptr;
}