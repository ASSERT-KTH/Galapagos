Version 1:

void sodium_free(void *ptr)
{
    if (ptr == NULL) {
        return;
    }
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         unprotected_size;
    size_t         total_size;

    canary_ptr      = ((unsigned char *) ptr) - sizeof canary;
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr        = unprotected_ptr - page_size * 2U;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = page_size * 3 + unprotected_size;

    if ((sodium_memcmp(canary_ptr, canary, sizeof canary) != 0) 
        #ifndef HAVE_PAGE_PROTECTION 
        || (sodium_memcmp(canary + unprotected_ptr + unprotected_size, canary,
                      sizeof canary) != 0)
        #endif)         
    {
        _out_of_bounds();
    }
    else {
        _mprotect_readwrite(base_ptr, total_size);
        (void) sodium_munlock(unprotected_ptr, unprotected_size);
        _free_aligned(base_ptr, total_size);
    }
}


Version 2:

void sodium_free(void *ptr)
{
    if (ptr != NULL) {
        unsigned char *base_ptr;
        unsigned char *canary_ptr;
        unsigned char *unprotected_ptr;
        size_t unprotected_size;
        size_t total_size;

        canary_ptr      = ((unsigned char *) ptr) - sizeof canary;
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr        = unprotected_ptr - page_size * 2U;
        memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
        total_size = page_size * 3U + unprotected_size;

        _mprotect_readwrite(base_ptr, total_size);

        if (sodium_memcmp(canary_ptr, canary, sizeof canary)) {
            _out_of_bounds();
        }
        #ifndef HAVE_PAGE_PROTECTION
        else if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary)) {
            _out_of_bounds();
        }
        #endif
        else {
           (void) sodium_munlock(unprotected_ptr, unprotected_size);
           _free_aligned(base_ptr, total_size); 
        }
    }
}


NOTE: You truly see the parallel between the two versions in this approach: Each preserves the main functionality. Canaries are moved to a different position compared to a bounds check which is placed around the main body of operations: `_mprotect_readwrite`, `sodium_munlock`, and `_free_aligned`.
