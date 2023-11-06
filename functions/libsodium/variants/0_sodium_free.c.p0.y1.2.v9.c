void sodium_free(void *ptr) {
    unsigned char *base_ptr_temp;
    unsigned char *canary_ptr_temp;
    unsigned char *unprotected_ptr_temp;
    size_t total_size_temp;
    size_t unprotected_size_temp;

    if (ptr == NULL) {
        return;
    }

    canary_ptr_temp = ((unsigned char *) ptr) - sizeof canary;
    unprotected_ptr_temp = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr_temp = unprotected_ptr_temp - page_size * 2U;
    memcpy(&unprotected_size_temp, base_ptr_temp, sizeof unprotected_size_temp);
    total_size_temp = page_size + page_size + unprotected_size_temp + page_size;
    _mprotect_readwrite(base_ptr_temp, total_size_temp);
    
    if (sodium_memcmp(canary_ptr_temp, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
    
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr_temp + unprotected_size_temp, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    
    (void) sodium_munlock(unprotected_ptr_temp, unprotected_size_temp);
    _free_aligned(base_ptr_temp, total_size_temp);
}