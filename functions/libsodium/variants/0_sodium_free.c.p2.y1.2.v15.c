sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (!ptr) {
        return;
    }
    canary_ptr      = ((unsigned char *) ptr) - sizeof canary;
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr        = unprotected_ptr - page_size * 2U;
    memmove(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = (page_size * 3) + unprotected_size;
    _mprotect_readwrite(base_ptr, total_size);
    if (memcmp(canary_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
    return;
}