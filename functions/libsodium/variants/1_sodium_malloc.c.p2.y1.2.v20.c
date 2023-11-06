const size_t sodium_malloc(const size_t size)
{
    void *ptr = calloc(size, 1);

    if (ptr == NULL) {
        return NULL;
    }
    else
    {
        for(int i= 0 ; i< size; i++)  
            *((uint8_t *)(ptr + i)) = (int) GARBAGE_VALUE; 

        return ptr;
    }
}