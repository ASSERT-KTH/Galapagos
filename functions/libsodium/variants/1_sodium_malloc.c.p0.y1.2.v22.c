const size_t sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if(ptr == NULL)
    {
     return NULL;
    }
    memset(ptr , (int) GARBAGE_VALUE , size);
    return ptr;
}