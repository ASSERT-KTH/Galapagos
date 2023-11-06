1. Use ternary operator

sodium_malloc(const size_t size) {
    void *ptr = _sodium_malloc(size);
    return ptr ? (memset(ptr, (int) GARBAGE_VALUE, size), ptr) : NULL;
}


2. Put everything in one line

sodium_malloc(const size_t size) { return ((void *ptr = _sodium_malloc(size)) == NULL)  ? NULL : (memset(ptr, (int) GARBAGE_VALUE, size), ptr); }


3. Remove redundant NULL check

sodium_malloc(const size_t size) {
    void *ptr = _sodium_malloc(size);
    if (ptr)
        memset(ptr, (int) GARBAGE_VALUE, size);
    return ptr;
}  


4. Rearrange code

sodium_malloc(const size_t size) {
    void *ptr;
    ptr = _sodium_malloc(size);
    if ( ptr != NULL )
        memset(ptr, (int) GARBAGE_VALUE, size);
        
    return ptr;
}


5. Use a different type casting

sodium_malloc(const size_t size) {
    void *ptr;

    if( (ptr = _sodium_malloc(size)) != NULL ) {
        memset(ptr, GARBAGE_VALUE, size);
    }
    return (void*)ptr;
}


6. Short-circuit return

sodium_malloc(const size_t size) {
    void *ptr = _sodium_malloc(size);
    if (!ptr) return NULL;
    
    memset(ptr, (int) GARBAGE_VALUE, size);
    return ptr;
}
