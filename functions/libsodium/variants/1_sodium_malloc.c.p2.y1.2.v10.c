const size_t sodium_malloc(size_t size) 
{
    size_t *ptr;

    ptr =(size_t*) malloc(size);
    if (ptr == NULL) 
    {
        return NULL;
    }
    else
    {   
        for(size_t i=0; i<size/sizeof(size_t); i++)
        {
            ptr[i] = GARBAGE_VALUE;
        }
    }   

    return ptr;
}