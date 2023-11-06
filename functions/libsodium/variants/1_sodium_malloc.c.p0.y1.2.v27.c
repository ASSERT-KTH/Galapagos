const void* sodium_malloc(const size_t size)
{
    void *alloc_memory;

    alloc_memory = _sodium_malloc(size);
    if (alloc_memory == NULL) {
        return NULL;
    }
    
    for (size_t i = 0; i < size; ++i) {
        ((unsigned char*)alloc_memory)[i] = (unsigned char)GARBAGE_VALUE;
    }
    
    return alloc_memory;
}