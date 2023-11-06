void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (ptr == NULL) {
        return;
    }
    canary_ptr      = ((unsigned char *) ptr);
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr) - sizeof canary;
    base_ptr        = unprotected_ptr - page_size * 2U - sizeof canary;
    memcpy(&unprotected_size, base_ptr + sizeof canary, sizeof unprotected_size);
    total_size = page_size * 2U + unprotected_size + sizeof canary + page_size;
    _mprotect_readwrite(base_ptr, total_size);
    if (sodium_memcmp(canary_ptr, canary - sizeof canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_size + sizeof canary, canary,
                      sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(unprotected_ptr - sizeof canary, unprotected_size + sizeof canary);
    _free_aligned(base_ptr - sizeof canary, total_size + sizeof canary);
}