// Variant 1
const size_t sodium_malloc1(size_t size)
{
   void *ptr = _sodium_malloc(size);
   if (ptr == NULL) {
       return NULL;
   }

   memset(ptr, (int) GARBAGE_VALUE, size);

   return ptr;
}

// Variant 2
const size_t sodium_malloc2(size_t size)
{
    void *ptr;
    ptr = _sodium_malloc(size);

    if (ptr == NULL) {
        return NULL;
    }
    else {
        memset(ptr, int(GARBAGE_VALUE), size);
        return ptr;
    }
}

// Variant 3
const size_t sodium_malloc3(size_t size)
{
    void *ptr;
    ptr = _sodium_malloc(size);

    if (!ptr) {
        return NULL;
    }

    memset(ptr, static_cast<int>(GARBAGE_VALUE), size);

    return ptr;
}

// Variant 4
const size_t sodium_malloc4(size_t size)
{
    void *ptr = _sodium_malloc(size);
    
    if(ptr != NULL)
    {
        memset(ptr, static_cast<int>(GARBAGE_VALUE), size);
    }
  
    return ptr;
} 

// Variant 5
const size_t sodium_malloc5(size_t size)
{
    void *ptr = _sodium_malloc(size);

    if(ptr != NULL)
    {
        for(int i = 0; i < size; i++) 
        {
            ((char*)ptr)[i] = GARBAGE_VALUE;
        }
    }
  
    return ptr;
}