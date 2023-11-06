const size_t sodium_malloc(size_t size)
{
    void *ptr;
    
    ptr = _sodium_malloc(size);
    if (ptr == NULL) {
        return NULL;
    } 
    for(int i = 0; i < size; i++) {
        ((unsigned char*)ptr)[i] = (unsigned char)GARBAGE_VALUE;
    }

    return ptr;
}