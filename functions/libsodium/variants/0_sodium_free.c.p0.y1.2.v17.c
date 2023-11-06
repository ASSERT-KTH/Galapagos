void sodium_free(void *ptr) 
{
    unsigned char *base_pointer;
    unsigned char *canary_point;
    unsigned char *exposed_pointer;
    size_t         full_size;
    size_t         exposed_size;

    if (ptr != NULL) {
        canary_point      = ((unsigned char *) ptr) - sizeof canary;
        exposed_pointer = _unprotected_ptr_from_user_ptr(ptr);
        base_pointer        = exposed_pointer - 2* page_size;
        memcpy(&exposed_size, base_pointer, sizeof exposed_size);
        full_size = 3* page_size + exposed_size;
        _mprotect_readwrite(base_pointer, full_size);
        if (sodium_memcmp(canary_point, canary, sizeof canary)) {
            _out_of_bounds();
        }
# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(exposed_pointer + exposed_size, canary,
                          sizeof canary)) {
            _out_of_bounds();
        }
# endif
        (void) sodium_munlock(exposed_pointer, exposed_size);
        _free_aligned(base_pointer, full_size);
    }
}