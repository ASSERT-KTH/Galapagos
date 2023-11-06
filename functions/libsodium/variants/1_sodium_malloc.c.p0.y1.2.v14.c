void* sodium_malloc(const size_t size)
{
    void *alloc;

    alloc = _sodium_malloc(size);
    if (!alloc) {
        return NULL;
    }
    
    for (size_t i = 0; i < size; i++) {
         *((unsigned char*)alloc+i) = (unsigned char) GARBAGE_VALUE;
    }

    return alloc;
}