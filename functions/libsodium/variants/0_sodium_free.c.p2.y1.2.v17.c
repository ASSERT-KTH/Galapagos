void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *terminator_ptr;
    unsigned char *unsecure_ptr;
    size_t         full_extent;
    size_t         unsecure_extent;

    if (ptr != NULL) {
        terminator_ptr      = ((unsigned char *) ptr) - sizeof canary;
        unsecure_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr        = unsecure_ptr - page_size * 2U;
        memcpy(&unsecure_extent, base_ptr, sizeof unsecure_extent);
        full_extent = 2 * page_size + unsecure_extent + page_size;
        _mprotect_readwrite(base_ptr, full_extent);
        if (sodium_memcmp(terminator_ptr, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(unsecure_ptr + unsecure_extent, canary,
                          sizeof canary) != 0) {
            _out_of_bounds();
        }
# endif
        (void) sodium_munlock(unsecure_ptr, unsecure_extent);
        _free_aligned(base_ptr, full_extent);
    }
}