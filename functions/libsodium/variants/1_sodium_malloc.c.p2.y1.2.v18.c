sodium_malloc(const size_t size)
{
    void *ptr = NULL;
    
    if ((size == 0) || ((ptr = _sodium_malloc(size)) == NULL)) {
        return NULL;
    }
    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}