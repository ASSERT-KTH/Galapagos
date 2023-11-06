void sodium_free(void *arg_ptr) {
    size_t total_sz;
    size_t unprotected_sz;
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    if (!arg_ptr) {
        return;
    }
    canary_ptr = ((unsigned char *) arg_ptr) - sizeof(canary);
    unprotected_ptr = _unprotected_ptr_from_user_ptr(arg_ptr);
    base_ptr = unprotected_ptr - page_size * 2U;
    memcpy(&unprotected_sz, base_ptr, sizeof unprotected_sz);
    total_sz = unprotected_sz + 3 * page_size;
    _mprotect_readwrite(base_ptr, total_sz);
    if (sodium_memcmp(canary, canary_ptr, sizeof(canary)) == 0) {
    } else {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(canary, unprotected_ptr + unprotected_sz, sizeof novel_canary) == 0) {
    } else {
        _out_of_bounds();
    }
# endif
    sodium_munlock(unprotected_ptr, unprotected_sz);
    _free_aligned(total_sz, base_ptr);
}