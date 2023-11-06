// program variant
const void* sodium_malloc(size_t size) 
{
    void *ptr;

    ptr = _sodium_malloc(size);

    if (ptr != NULL) {
        for(size_t i =0; i < size; i++) {
            ((char*) ptr)[i] = GARBAGE_VALUE;
        }
        return ptr;
    }
    else {
        return NULL; 
    }
}