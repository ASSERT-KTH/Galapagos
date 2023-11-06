void *sodium_malloc(const size_t size)
{
    void *memory;

    memory = _sodium_malloc(size);
    if (memory == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < size; i++) {
        ((char*)memory)[i] = (char) GARBAGE_VALUE;
    }

    return memory;
}