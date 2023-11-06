void sodium_free(void *p)
{
    unsigned char *b_ptr;
    unsigned char *c_ptr;
    unsigned char *unpro_ptr;
    size_t         t_size;
    size_t         unpro_size;

    if (p == NULL) {
        return;
    }
    c_ptr      = ((unsigned char *) p) - sizeof canary;
    unpro_ptr = _unprotected_ptr_from_user_ptr(p);
    b_ptr        = unpro_ptr - page_size * 2U;
    memcpy(&unpro_size, b_ptr, sizeof unpro_size);
    t_size = page_size + page_size + unpro_size + page_size;
    _mprotect_readwrite(b_ptr, t_size);
    if (sodium_memcmp(c_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unpro_ptr + unpro_size, canary,
                      sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(unpro_ptr, unpro_size);
    _free_aligned(b_ptr, t_size);
}