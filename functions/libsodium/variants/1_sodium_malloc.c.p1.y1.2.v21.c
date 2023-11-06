Variant 1:


const size_t sodium_malloc(size_t size){
    void *ptr = _sodium_malloc(size);
    if (ptr == NULL) {
        return NULL;
    } else {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }

    return ptr;
}


Variant 2:


const size_t sodium_malloc(size_t size){
    void *ptr = NULL;
    if ((ptr = _sodium_malloc(size))) {
        memset(ptr, (int) GARBAGE_VALUE, size);
        return ptr;
    }

    return NULL;
}
 

Variant 3:


const size_t sodium_malloc(size_t size){
    void *ptr = _sodium_malloc(size);

    if (!ptr) 
        return NULL;

    memset(ptr, (int) GARBAGE_VALUE, size);
    return ptr;
}
 

Variant 4:


const size_t sodium_malloc(size_t size){
    void *ptr = _sodium_malloc(size);

    if (ptr == NULL) 
        return NULL;

    memset(ptr, (int) GARBAGE_VALUE, size);
    return ptr;
}
 