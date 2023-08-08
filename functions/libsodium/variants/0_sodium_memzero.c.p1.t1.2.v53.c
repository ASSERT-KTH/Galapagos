Here is a different implementation of the `sodium_memzero` function in C:


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_MSC_VER)
    SecureZeroMemory(pnt, len); // use SecureZeroMemory if Microsoft C Runtime library in use
#else
    volatile char *v = (char*)pnt;
    if(v!=NULL)
    {
        size_t n = len;

        /*
         * Using the XOR operator '^' as a way to set all bits = 0 within the bounds of the block.
         * XOR with itself always results in false (0), hence zeroing memory blockbit set of memory block pnt indicates the end.
         */
       
        while(n)
        {
            *v ^= *v;
            v++;
            n--;
        }
    }
#endif
}


In this `sodium_memzero` alternative, memory checking is explicitly done using NULL checking before proceeding with the memory manipulation operation in the else structure. Instead of using different library functions like memzero or memset, using the XOR with itself which results in 0 (false), whereby zeroing the memory blocks where pointer pnt points towards all happens on the basis of bit manipulation which is usually faster.