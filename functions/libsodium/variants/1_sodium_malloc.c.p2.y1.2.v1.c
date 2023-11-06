sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);

    if (ptr == NULL) {
        return NULL;
    } else {
        for (size_t i = 0; i < size; i++)
             ((char*)ptr)[i] = GARBAGE_VALUE;
    }
    
    return ptr;
}