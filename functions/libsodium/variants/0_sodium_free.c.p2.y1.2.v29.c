void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (!ptr) {
        return;
    }

    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    canary_ptr      = ((unsigned char *) ptr) - sizeof canary;
    base_ptr        = unprotected_ptr - (2U * page_size);
    unprotected_size = *(size_t*)(base_ptr);
    total_size = (3 * page_size) + unprotected_size;

    _mprotect_readwrite(base_ptr, total_size);
    int cmpResult = sodium_memcmp(canary_ptr, canary, sizeof canary);
    # ifndef HAVE_PAGE_PROTECTION
        cmpResult += sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary);
    # endif
    if (cmpResult != 0) {
        _out_of_bounds();
    }

    sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
}
