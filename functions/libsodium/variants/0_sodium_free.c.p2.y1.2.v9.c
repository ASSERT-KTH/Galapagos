void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *unprotected_ptr;
    unsigned char *canary_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (ptr == NULL) {
        return;
    }
    
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    canary_ptr = ((unsigned char *) ptr) - sizeof canary;
    base_ptr = unprotected_ptr - page_size * 2U;
    (void) sodium_munlock(unprotected_ptr, unprotected_size);

    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = page_size * 3 + unprotected_size;
    _mprotect_readwrite(base_ptr, total_size);

    if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
    else{
    # ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(unprotected_ptr + unprotected_size, canary,
                      sizeof canary) != 0) {
        _out_of_bounds();
        }
     # endif
     _free_aligned(base_ptr, total_size);
    }
}