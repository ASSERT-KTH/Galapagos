The function can have similar performance, just use a different approach. Following is a function code that uses the memset function and a volatile pointer. Later the reference of this pointer is set to NULL, it doesn't represent any change in behavior because the actual memory is already set to zero:


sodium_memzero(void * const pnt, const size_t len)
{
    volatile char *volatile vlt_ptr = (volatile char *volatile)pnt;
    
    if (!vlt_ptr) 
        return;

    memset((void *)vlt_ptr, 0, len);

    vlt_ptr = NULL;        
}


Or, using a for loop to set the memory to zero manually:


sodium_memzero(void * const pnt, const size_t len)
{
    volatile unsigned char *vlt_ptr = (volatile unsigned char *)pnt;

    if (!vlt_ptr) 
        return;

    for (size_t i = 0; i < len; ++i) {
        vlt_ptr[i] = 0;
    }

    vlt_ptr = NULL;
}


In these examples, the volatile pointer itself is set to NULL. This does not directly modify the underlying block of memory, and does act as a type of pointer-to-pointer mechanism of nullifying a memory address. But regardless of this act, the required functionality of the function is to nullify a memory block which has been properly performed. After completing its function the additional act of nullifying the volatile pointer doesn't nullify the function's outcome therefore it's considered as maintaining the original functionality(which is nullifying a memory block).