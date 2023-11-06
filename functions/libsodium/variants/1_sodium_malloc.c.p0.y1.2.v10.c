const void* sodium_malloc(const size_t size) 
{
    void *ptr = _sodium_malloc(size);

    if (!ptr) 
    {
        return NULL;
    }

    for (size_t i = 0; i < size; i++) 
    {
        ((unsigned char*)ptr)[i] = (unsigned char) GARBAGE_VALUE;
    }

    return ptr;
}