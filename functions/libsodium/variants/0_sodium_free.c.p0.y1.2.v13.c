void sodium_free(void *ptr)
{
    if (!ptr) {
        return;
    }
    
    unsigned char *user_ptr = (unsigned char *) ptr;
    unsigned char *canary_position = user_ptr - sizeof(canary);
    size_t unprotected_size;
    total_size;
    unsigned char *start;
    unsigned char *unprotected_start = _unprotected_ptr_from_user_ptr(ptr);

    start = unprotected_start - page_size * 2U;
    memcpy(&unprotected_size, start, sizeof unprotected_size);
    total_size = unprotected_size + 3U * page_size;

    _mprotect_readwrite(start, total_size);
    
    if (sodium_memcmp(canary_position, canary, sizeof canary)) {
        _out_of_bounds();
    }

# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_start + unprotected_size, canary, sizeof canary)) {
        _out_of_bounds();
    }
# endif

    (void) sodium_munlock(unprotected_start, unprotected_size);
    _free_aligned(start, total_size);
}