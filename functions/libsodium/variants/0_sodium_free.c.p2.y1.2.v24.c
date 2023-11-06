void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t total_size;
    size_t unprotected_size;

    if (ptr != NULL) {
        canary_ptr = ((unsigned char *) ptr) - sizeof(canary);
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr = unprotected_ptr - (2 * page_size);
        memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
        total_size = (3 * page_size) + unprotected_size;

        _mprotect_readwrite(base_ptr, total_size);
        
        //merged memcmp check into one if clause
        if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0
# ifndef HAVE_PAGE_PROTECTION
           || sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary) != 0    
# endif 
        )
        {
            _out_of_bounds();
        }

        //emoved cast to void on sodium unlock pass its vars directly
        sodium_munlock(unprotected_ptr, unprotected_size);
        _free_aligned(base_ptr, total_size);
    }
}