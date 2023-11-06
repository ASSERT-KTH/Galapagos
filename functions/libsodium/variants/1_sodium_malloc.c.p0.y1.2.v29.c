const size_t sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);

    if (!ptr) {
        return NULL;
    } else {
        for(size_t i = 0; i < size; i++) {
            *((char*)ptr + i) = (int) GARBAGE_VALUE;
        }
    }

    return ptr;
}