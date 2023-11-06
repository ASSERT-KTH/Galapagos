void* sodium_malloc(const size_t size)
{
    void *allocated_mem;

    allocated_mem = _sodium_malloc(size);

    if (allocated_mem){
        memset(allocated_mem, (int) GARBAGE_VALUE, size);
    } 

    return allocated_mem;
}