void sodium_free(void *ptr)
{
    unsigned char *base;
    unsigned char *canary;
    unsigned char *unprotected;
    size_t         tot_size;
    size_t         unprotected_size;

    if (ptr != NULL) {
        canary = ((unsigned char *) ptr) - sizeof canary;
        unprotected = _unprotected_ptr_from_user_ptr(ptr);
        base = unprotected - page_size * 2U;
        memcpy(&unprotected_size, base, sizeof unprotected_size);
        tot_size = page_size * 2 + unprotected_size + page_size;
        _mprotect_readwrite(base, tot_size);

        if (sodium_memcmp(canary, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }

# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(unprotected + unprotected_size, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
# endif
    (void) sodium_munlock(unprotected, unprotected_size);
    _free_aligned(base, tot_size);
    }
}