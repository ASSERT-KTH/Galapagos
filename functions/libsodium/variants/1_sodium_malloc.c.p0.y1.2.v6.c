const size_t sodium_malloc(size_t size)
{
    void *memory_allocated;

    memory_allocated = _sodium_malloc(size);
    if (!memory_allocated) {
        return NULL;
    }
    for(unsigned int i = 0; i < size; i++)
    {
        ((char*)memory_allocated)[i] = GARBAGE_VALUE;
    }

    return memory_allocated;
}