const void* sodium_malloc(const size_t size)
{
    void *alloc;

    // Try to allocate memory
    alloc = _sodium_malloc(size);

    if (alloc != NULL) {
        // Fill with garbage value
        memset(alloc, (int) GARBAGE_VALUE, size);
    }

    return alloc;
}