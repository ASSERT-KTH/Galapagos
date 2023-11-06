Variant 1:

void sodium_free(void *ptr)
{
    if (ptr == NULL) {
        return;
    }
    unsigned char *base_ptr;
    unsigned char *canary_ptr = ((unsigned char *) ptr) - sizeof canary;
    unsigned char *unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr = unprotected_ptr - page_size * 2U;
    size_t unprotected_size;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    size_t total_size = page_size*2 + unprotected_size + page_size ;
    _mprotect_readwrite(base_ptr, total_size);
    if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
#endif
    (void) sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
}

Variant 2:

void sodium_free(void *ptr)
{
    if (!(ptr)) {
        return;
    }
    unsigned char *base_ptr;
    unsigned char *unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr = unprotected_ptr - (page_size * 2);
    size_t unprotected_size;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    unsigned char *canary_ptr = ((unsigned char *) ptr) - sizeof canary;
    size_t total_size = ((page_size + page_size + unprotected_size) + page_size);

    _mprotect_readwrite(base_ptr, total_size);
    if (sodium_memcmp(canary_ptr, canary, sizeof canary)) {
        _out_of_bounds();
    }
#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary)) {
        _out_of_bounds();
    }
#endif
    sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
}
