Variant 1:

void * sodium_malloc(const size_t size) {
    void *ptr = _sodium_malloc(size);

    if(ptr) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }

    return ptr;
}

Variant 2:

void * sodium_malloc(const size_t size) {
    void* ptr = _sodium_malloc(size);
    if(ptr != NULL) {
        memset(ptr, (int) GARBAGE_VALUE, size);
        return ptr;
    }
    else {
        return NULL;
    }
}


Variant 3:

void * sodium_malloc(const size_t size) {
    void *ptr = _sodium_malloc(size);
    
    if(ptr != NULL) {
        for(size_t i = 0; i < size; i++) {
            ((char*)ptr)[i] = (GARBAGE_VALUE);
        }
    }
    return ptr;
}


Variant 4:

void * sodium_malloc(const size_t size) {
    
    void *ptr = NULL;
    ptr = _sodium_malloc(size);
    
    if(ptr != NULL) {   
        memset(ptr, (int) GARBAGE_VALUE, size);
        return ptr;
    }
    else {
        return NULL;
    }
}
