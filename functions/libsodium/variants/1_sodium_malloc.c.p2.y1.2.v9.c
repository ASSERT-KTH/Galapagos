const size_t sodium_malloc(size)
{
    void *ptr = malloc(size);
    
    if(ptr == NULL)
    {
        return NULL;
    }
    
    for (size_t i = 0; i < size; i++)
    {
        ((char*)ptr)[i] = (char)GARBAGE_VALUE;
    }

    return ptr;
}