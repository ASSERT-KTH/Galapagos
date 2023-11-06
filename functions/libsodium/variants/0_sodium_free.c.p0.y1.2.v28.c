void sodium_free(void *ptr)
{
    unsigned char *beginning_ptr;
    unsigned char *sentinel_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size_inclusive;
    size_t         unprotected_size;

    if (ptr != NULL) {
        sentinel_ptr   = ((unsigned char *) ptr) - sizeof canary;
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
        beginning_ptr    = unprotected_ptr - page_size * 2U;
        memcpy(&unprotected_size, beginning_ptr, sizeof unprotected_size);
        total_size_inclusive = (page_size * 3U) + unprotected_size;
        _mprotect_readwrite(beginning_ptr, total_size_inclusive);
        
        if (sodium_memcmp(sentinel_ptr, canary, sizeof canary) != 0) { 
            _out_of_bounds(); 
        }
        
    # ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
    # endif
        
        (void) sodium_munlock(unprotected_ptr, unprotected_size);
        _free_aligned(beginning_ptr, total_size_inclusive);
    }
}