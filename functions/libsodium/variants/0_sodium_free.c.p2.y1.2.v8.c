void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *user_ptr;
    size_t         total_size;
    size_t         user_size;

    if (ptr != NULL) {
        
        canary_ptr      = ((unsigned char *) ptr) - sizeof canary;
        user_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr        = user_ptr - page_size * 2U;

        // Make a copy of the size before the pointer can get trashed
        user_size = *(size_t *)base_ptr;

        total_size = (2U * page_size) + user_size + page_size;

        _mprotect_readwrite(base_ptr, total_size);
        
        if (0 != sodium_memcmp(canary_ptr, canary, sizeof canary)) { //_compare_zero for clarity and some other place's consider it safer against timing attacks.
            _out_of_bounds();
        }
# ifndef HAVE_PAGE_PROTECTION
        if (0 !=  sodium_memcmp(user_ptr + user_size, canary, sizeof canary)) {
            _out_of_bounds();
        }
# endif
        (void) sodium_munlock(user_ptr, user_size);

        _free_aligned(base_ptr, total_size);
    }  
}