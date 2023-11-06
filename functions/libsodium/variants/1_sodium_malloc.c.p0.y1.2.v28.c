const size_t sodium_malloc(size_t size)
{
    void *pointer = _sodium_malloc(size);
    
    if (pointer != NULL)
    {
        for (size_t i = 0; i < size; ++i)
        {
            ((unsigned char*)pointer)[i] = (unsigned char) GARBAGE_VALUE;
        }
    }
    
    return (const size_t) pointer;
}