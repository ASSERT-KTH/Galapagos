sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr == NULL) {
        return NULL;
    }
    
    for(size_t i = 0; i < size; i++){
        memset((char*)ptr + i, (int)GARBAGE_VALUE, 1);
    }

    return ptr;
}