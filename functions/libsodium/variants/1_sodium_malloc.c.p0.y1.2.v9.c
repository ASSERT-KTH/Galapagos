const void* sodium_malloc(const size_t size)
{
    void *point;

    if (!(point = _sodium_malloc(size))) {
        return NULL;
    }
    for (size_t i = 0; i < size; i++)
    {
        *(char *)(point + i) = (int) GARBAGE_VALUE;
    }

    return point;
}