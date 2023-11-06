const size_t sodium_malloc(size_t size)
{
    const size_t allocSize = size;
    void *allocPointer = NULL;

    if (!(allocPointer = _sodium_malloc(allocSize))) {
        return NULL;
    }

    memset(allocPointer, (int) GARBAGE_VALUE, allocSize);

    return allocPointer;
}