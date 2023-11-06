sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (ptr == NULL) 
        return;
    
    base_ptr        = _unprotected_ptr_from_user_ptr(ptr) - 2U * page_size;
    canary_ptr      = ((unsigned char *) ptr) - sizeof canary;
  
    if (sodium_memcmp(canary_ptr, canary, sizeof canary)) {
        _out_of_bounds();
    }

    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = 3U* page_size + unprotected_size;
    _mprotect_readwrite(base_ptr, total_size);

# ifndef HAVE_PAGE_PROTECTION
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(base_ptr + 2U * page_size, unprotected_size);
    _free_aligned(base_ptr, total_size);
}