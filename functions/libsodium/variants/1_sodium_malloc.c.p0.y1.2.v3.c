void* sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (!ptr) { // if ptr is NULL
        return NULL;
    }
    else {
        for (size_t i = 0; i< size; i++)
             *((char*)ptr + i) = (char) GARBAGE_VALUE; 
        return ptr;
    }
}