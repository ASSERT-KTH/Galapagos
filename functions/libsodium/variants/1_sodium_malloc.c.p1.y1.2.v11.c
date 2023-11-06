Variant 1:

void* sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr == NULL) {
        return NULL;
    }
    for(size_t i = 0; i < size; ++i) {
        ((unsigned char*)ptr)[i] = (unsigned char) GARBAGE_VALUE;
    }
    return ptr;
}


Variant 2:

void* sodium_malloc(const size_t size)
{
    void *ptr;
    ptr = _sodium_malloc(size);
    if(ptr == NULL){
        return NULL;
    } 
    else {
        memset(ptr, (int) GARBAGE_VALUE, size);
        return ptr;
    }
}


Variant 3:

void* sodium_malloc(const size_t size){
    void* ptr = _sodium_malloc(size);
    if(ptr){
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    return ptr;
}
    

Variant 4:

void* sodium_malloc(const size_t size)
{
    void *ptr;
    if ((ptr = _sodium_malloc(size)))
    {
        memset(ptr, (int) GARBAGE_VALUE, size);
        return ptr;
    }
    else
    {
        return NULL;
    }
}


Variant 5:

void* sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr != NULL) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    return ptr;
}
