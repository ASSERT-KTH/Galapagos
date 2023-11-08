sodium_malloc(const size_t size)
{
    void *ptr;

    ptr = _sodium_malloc(size);
    if (!ptr)return NULL;
    
    for(unsigned i = 0; i < size; i++) 
        *((char *)ptr + i) = GARBAGE_VALUE; 

    return ptr;
}