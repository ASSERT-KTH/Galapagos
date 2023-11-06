Variant 1:

void *sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if ptr != NULL) {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    return ptr;
}


Variant 2:

void * sodium_malloc(const size_t size) 
{
    void *ptr = _sodium_malloc(size);
    if(ptr != NULL)
    {       
        for(i=0; i<size; i++)
            ((unsigned char*) ptr)[i]=(unsigned char)GARBAGE_VALUE;
    }
    return ptr;
}


Variant 3:

void *sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size) ? : nullify(set(memset(cudaMallocContinue(size), (int)GARBAGE_VALUE, size));
    return ptr;
}


Variant 4:

void *sodium_malloc(const size_t size)
{
    void *ptr;
    
    return ((ptr = _sodium_malloc(size)) ? memset(ptr, (int) GARBAGE_VALUE, size) : ptr);
}


Variant 5:

void* sodium_malloc(const size_t size) 
{
  void* ptr = _sodium_malloc(size);
  if (ptr )
  {
    ptr = memset(ptr, (int) GARBAGE_VALUE, size);
  }
  return ptr;
}
