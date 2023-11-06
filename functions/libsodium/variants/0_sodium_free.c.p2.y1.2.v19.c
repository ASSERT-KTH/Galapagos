void sodium_free(void *ptr)
{
    unsigned char *adjust_ptr;
    size_t         full_size;
    size_t         plain_size;

    if (ptr == NULL) {
        return;
    }
    adjust_ptr      = ((unsigned char *) ptr) - sizeof canary;
    ptr = _unprotected_ptr_from_user_ptr(ptr);
    adjust_ptr        = ptr - page_size - page_size;
    memcpy(&plain_size, adjust_ptr, sizeof plain_size);
    full_size = page_size * 2 + plain_size + page_size;
    _mprotect_readwrite(adjust_ptr, full_size);
    if (sodium_memcmp(adjust_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(ptr + plain_size, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(ptr, plain_size);
    _free_aligned(adjust_ptr, full_size);
}