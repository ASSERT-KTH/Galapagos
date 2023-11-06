const size_t sodium_malloc(size_t size)
{
    void *allocated_memory;
    allocated_memory = _sodium_malloc(size);

    if (!allocated_memory) {
        return NULL;
    }
    else {
        memset(allocated_memory, (int) GARBAGE_VALUE, size);
        return allocated_memory;
    }
}