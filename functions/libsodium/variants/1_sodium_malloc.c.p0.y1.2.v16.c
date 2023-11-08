const size_t sodium_malloc(size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (!ptr) {
        return NULL;
    }
    for (size_t i=0; i<size; i++) {
        ((unsigned char*)ptr)[i] = (unsigned char) GARBAGE_VALUE;
    }
    return ptr;
}