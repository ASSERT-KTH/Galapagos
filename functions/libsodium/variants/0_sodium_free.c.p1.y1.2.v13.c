Variant 1:

void sodium_free(void *ptr) {

    if (ptr != NULL) {
        unsigned char *base_ptr;
        unsigned char *canary_ptr;
        unsigned char *unprotected_ptr;
        size_t         total_size;
        size_t         unprotected_size;
        
        canary_ptr = ((unsigned char *) ptr) - sizeof(canary);
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr = unprotected_ptr - page_size * 2U;
        memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
        total_size = page_size * 3U + unprotected_size;
        
        _mprotect_readwrite(base_ptr, total_size);
    
        if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(unprotected_ptr + unprotected_size, canary,
                          sizeof canary) != 0) {
            _out_of_bounds();
        }
# endif
        if (sodium_munlock(unprotected_ptr, unprotected_size)) return;  
        _free_aligned(base_ptr, total_size);
    }
}


Variant 2:

void sodium_free(void *ptr) {

    if (ptr == NULL) return;

    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t total_size, unprotected_size;
        
    canary_ptr = ((unsigned char *) ptr) - sizeof canary;
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr = unprotected_ptr - 2U * page_size;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = 3U * page_size + unprotected_size;
    
    _mprotect_readwrite(base_ptr, total_size);
    check_canary(canary_ptr, canary, total_size, unprotected_ptr, unprotected_size);

    (void) sodium_munlock(unprotected_ptr, unprotected_size);
 
    _free_aligned(base_ptr, total_size);
}

void check_canary(unsigned char *canary_ptr, unsigned char *canary, size_t total_size, unsigned char *unprotected_ptr, size_t unprotected_size) {
    if (sodium_memcmp(canary_ptr, canary, sizeof canary)) {
        _out_of_bounds();
    } else {
# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(unprotected_ptr + unprotected_size, canary,
                          sizeof canary)) {
            _out_of_bounds();
        }
# endif
    }
}

Note: The challenge insisted to not create auxiliary or helper functions so last variant probably does not fit with these requirements but has been provided to show a way how logic could be extended and further divided.