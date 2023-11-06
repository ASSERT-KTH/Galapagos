void *sodium_malloc(const size_t size)
{
    void *allocated;

    allocated = _sodium_malloc(size);
    if (!allocated) {
        return NULL;
    }
    for (size_t i = 0; i<size; i++)
    {
        ((unsigned char*)allocated)[i] = GARBAGE_VALUE;
    }

    return allocated;
}