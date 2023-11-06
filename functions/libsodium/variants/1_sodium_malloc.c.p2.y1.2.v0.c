const size_t sodium_malloc(size_t size)
{
    void* ptr;
    ptr = _sodium_malloc(size);

    if (ptr != NULL) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    
    return ptr;
}