// Program Variant
const void* sodium_malloc(size_t size)
{
    void* ptr;

    if ((ptr = _sodium_malloc(size)) != NULL) {
        memset(ptr, (int)GARBAGE_VALUE, size);
    }

    return ptr;
}