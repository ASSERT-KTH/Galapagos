ealloc(size_t size)
{
    void *ptr = calloc(1, size);

    if (ptr == NULL)
        abort();
    return ptr;
}