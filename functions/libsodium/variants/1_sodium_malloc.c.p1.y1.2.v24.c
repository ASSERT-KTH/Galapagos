Variant 1:

const size_t sodium_malloc(size_t size)
{
    void* ptr = _sodium_malloc(size);

    if (!ptr) {
        return NULL;
    }

    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}

Variant 2:

const size_t sodium_malloc(size_t size)
{
    void* ptr;

    if (!(ptr = _sodium_malloc(size))) {
        return NULL;
    }
    
    for(size_t i = 0; i < size; i++){
        ((char*)ptr)[i] = GARBAGE_VALUE;  
    }

    return ptr;
}

Variant 3

const size_t sodium_malloc(size_t size)
{
    void* ptr = NULL;

    ptr = _sodium_malloc(size);
  
    if (ptr == NULL) {
        return NULL;
    }
  
    memset(ptr, GARBAGE_VALUE, size);

    return ptr;
}

Variant 4:

const size_t sodium_malloc(size_t size)
{
    void *ptr = _sodium_malloc(size);
     
    if(ptr != NULL) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }

    return ptr;
}
