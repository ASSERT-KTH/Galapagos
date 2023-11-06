void sodium_free(void *ptr)
{
    unsigned char *initial_ptr;
    unsigned char *verify_ptr;
    unsigned char *naked_ptr;
    size_t         full_size;
    size_t         naked_size;

    if (ptr != NULL) {
        
        verify_ptr      = ((unsigned char *) ptr) - sizeof canary;
        naked_ptr = _unprotected_ptr_from_user_ptr(ptr);
        initial_ptr = naked_ptr - 2U * page_size;
        memcpy(&naked_size, initial_ptr, sizeof naked_size);
        full_size = 3 * page_size + naked_size;

        _mprotect_readwrite(initial_ptr, full_size);

        if (sodium_memcmp(verify_ptr, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(naked_ptr + naked_size, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(naked_ptr, naked_size);
    _free_aligned(initial_ptr, full_size);
    }   
}