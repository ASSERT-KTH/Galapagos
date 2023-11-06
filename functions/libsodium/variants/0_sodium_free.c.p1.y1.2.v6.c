Variant 1:

void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *computed_canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_mem_size;

    if (ptr != NULL) 
    {
        computed_canary_ptr = ((unsigned char *) ptr) - sizeof canary;
        unprotected_ptr  = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr            = unprotected_ptr - page_size * 2;
        memcpy(&unprotected_mem_size, base_ptr, sizeof unprotected_mem_size);
        total_size = page_size * 2 + unprotected_mem_size + page_size;

        _mprotect_readwrite(base_ptr, total_size);
        
        if ((sodium_memcmp(computed_canary_ptr, canary, sizeof canary)) != 0)
        {
            _out_of_bounds();
        }
#ifndef HAVE_PAGE_PROTECTION   
        if ((sodium_memcmp(unprotected_ptr + unprotected_mem_size, canary, sizeof canary)) != 0)
        {
            _out_of_bounds();
        }
#endif
        (void) sodium_munlock(unprotected_ptr, unprotected_mem_size);
        _free_aligned(base_ptr, total_size);   
    }
}

Variant 2:

void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_location;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (ptr) 
    {
        canary_location = ((unsigned char *) ptr) - sizeof canary;
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr = unprotected_ptr - 2 * page_size;
        memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
        total_size = (3 * page_size) + unprotected_size;

        _mprotect_readwrite(base_ptr, total_size);

        if (sodium_memcmp(canary_location, canary, sizeof canary) != 0) 
        {
            _out_of_bounds();
        }
#ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary) != 0) 
        {
            _out_of_bounds();
        }
#endif
        (void) sodium_munlock(unprotected_ptr, unprotected_size);
        _free_aligned(base_ptr, total_size);
    }
}

These variants do not change the tests or calls that handle secure memory checks, rather they adjust the variables and the style are slightly modified with same logic.