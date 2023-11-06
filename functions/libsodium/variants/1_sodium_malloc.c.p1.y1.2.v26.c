1. Swapping the order of conditional checking


sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    
    if(ptr == NULL) {
        return NULL;
    }

    memset(ptr, (int)GARBAGE_VALUE, size);
   
    return ptr;
}


2. One-Liner Check


sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    
    return ptr ? (memset(ptr, (int)GARBAGE_VALUE, size), ptr): NULL;
}


3. Using Ternary Operator


sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);

    ptr ? memset(ptr, (int) GARBAGE_VALUE, size) : NULL;

    return ptr;
}
 

4. Inline Memory Allocation and Check


sodium_malloc(const size_t size)
{
    void *ptr;

    if((ptr = _sodium_malloc(size))) {
         memset(ptr, (int) GARBAGE_VALUE, size);
    }
    
    return ptr;
}


5. Expliciting the else clause


sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);

    if(ptr == NULL) {
        return NULL;
    } else {
        memset(ptr, (int)GARBAGE_VALUE, size);
        return ptr;
    }
}
