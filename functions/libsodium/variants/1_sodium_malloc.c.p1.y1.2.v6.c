Variant 1: Explicit cast

const size_t sodium_malloc(size_t size) {
    
    void *ptr = (void*) _sodium_malloc(size);
    
    if (ptr == NULL) {
        return NULL;
    }
    
    memset(ptr, (int) GARBAGE_VALUE, size);
    
    return ptr;
}


Variant 2: Use ternary operator for the condition

const size_t sodium_malloc(size_t size) {
    
    void *ptr = _sodium_malloc(size);

    return (ptr == NULL) ? NULL : memset(ptr, (int) GARBAGE_VALUE, size), ptr;
   
}


Variant 3: Reducing the lines of the if statement

const size_t sodium_malloc(size_t size) {
    
    void *ptr = _sodium_malloc(size);

    if (ptr == NULL) return NULL;
    
    memset(ptr, (int) GARBAGE_VALUE, size);
    
    return ptr;
}


Variant 4: Assert Version

const size_t sodium_malloc(size_t size) {
    assert(size > 0);
    void *ptr = _sodium_malloc(size);

    if (ptr == NULL) return NULL;

    memset(ptr, (int) GARBAGE_VALUE, size);

    return ptr;
}
