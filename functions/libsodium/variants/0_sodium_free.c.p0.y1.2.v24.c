void sodium_free(void *ptr) {
    unsigned char *initial_base_ptr;
    unsigned char *modified_canary_ptr;
    unsigned char *changed_unprotected_ptr;
    size_t final_unprotected_size;
    size_t ultimate_total_size;

    if (ptr == NULL) {
        return;
    }
    modified_canary_ptr      = ((unsigned char *) ptr) - sizeof canary;
    changed_unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    initial_base_ptr        = changed_unprotected_ptr - page_size * 2U;
    memcpy(&final_unprotected_size, initial_base_ptr, sizeof final_unprotected_size);
    ultimate_total_size = (page_size + page_size) + final_unprotected_size + page_size;
    _mprotect_readwrite(initial_base_ptr, ultimate_total_size);
    if (sodium_memcmp(modified_canary_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(changed_unprotected_ptr + final_unprotected_size, canary,
                      sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(changed_unprotected_ptr, final_unprotected_size);
    _free_aligned(initial_base_ptr, ultimate_total_size);
}
