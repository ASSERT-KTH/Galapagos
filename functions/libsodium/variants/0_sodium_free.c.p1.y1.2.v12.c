Variant 1:


sodium_free(void *ptr)
{
    unsigned char *unprotected_ptr, *base_ptr, *canary_ptr;
    size_t unprotected_size, total_size;

    if (!ptr) {
        return;
    }
    
    base_ptr = ((unsigned char *) ptr) - sizeof canary - page_size * 2U; 
    canary_ptr = ((unsigned char *) ptr) - sizeof canary;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    
    total_size = page_size*3U + unprotected_size;
    unprotected_ptr = (unknown_char *) ptr - unprotected_size;
    
    _mprotect_readwrite(base_ptr, total_size);
    
    if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0 || 
# ifndef HAVE_PAGE_PROTECTION
        sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary) != 0)
# endif
    {
        _out_of_bounds();
    }
    (void) sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
}


Variant 2:


sodium_free(void *ptr)
{
    unsigned char *base_ptr, *canary_ptr, *unprotected_ptr;
    size_t unprotected_size, total_size;

    if (ptr) {
        canary_ptr = (unsigned char *) ptr - sizeof canary;
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr = unprotected_ptr - page_size*2U; 
        memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
        
        total_size = page_size*3U + unprotected_size;
        _mprotect_readwrite(base_ptr, total_size);
        
        if (0 != sodium_memcmp(canary_ptr, canary, sizeof canary) 
# ifndef HAVE_PAGE_PROTECTION
            || 0 != sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary) 
# endif
        ) {
            _out_of_bounds();
        }
        (void) sodium_munlock(unprotected_ptr, unprotected_size);
        _free_aligned(base_ptr, total_size); 
    }
}


Please, make sure to place the function `_unprotected_ptr_from_user_ptr`, `_mprotect_readwrite`, `_out_of_bounds`, `sodium_munlock`, `_free_aligned` around your program and also, treat the global variables/canaries or condition variables properly in your own C program to compile obtained Program properly without Stack Overflow or memory managemant errors. Not supplying proper program may lead to ill functional behaviour of the derived program