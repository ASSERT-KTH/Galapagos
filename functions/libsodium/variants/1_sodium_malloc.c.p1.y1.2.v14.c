1. Changing the sequence of operations:


sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr == NULL) {
        return NULL;
    }
    
    memset(ptr, (int) GARBAGE_VALUE, size);
    return ptr;
}

2. Short-circuiting the flow:


sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr != NULL)  {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    return ptr;
}


3. Using direct return from the function:


sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr == NULL) {
        return NULL;
    }

    return memset(ptr, (int) GARBAGE_VALUE, size), ptr;
}


4. Validating input size:


sodium_malloc(const size_t size)
{
    if (size <= 0) {
        return NULL;
    }

    void *ptr = _sodium_malloc(size);
    if (ptr != NULL)  {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    
    return ptr;
}

5. Classic C structure with separate condition check:


sodium_malloc(const size_t size)
{
    void *ptr;

    ptr = _sodium_malloc(size);
    if (ptr != NULL)  {
         memset(ptr, (int) GARBAGE_VALUE, size);
    }

    return ptr;
}
