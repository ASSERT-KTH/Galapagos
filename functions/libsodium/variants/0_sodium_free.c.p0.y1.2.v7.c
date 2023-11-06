void sodium_free(void* ptr)
{
    if (!ptr) return;

    unsigned char *unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr), *base_ptr, *canary_ptr = ((unsigned char *) ptr) - sizeof canary;
    size_t total_size, unprotected_size;

    base_ptr = unprotected_ptr - 2U * page_size;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = unprotected_size + 2U * page_size + page_size;

    _mprotect_readwrite(base_ptr, total_size);

    if (sodium_memcmp(canary_ptr, canary, sizeof canary))
        _out_of_bounds();
    
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary))
        _out_of_bounds();
# endif

    sodium_munlock(unprotected_ptr, unprotected_size);

    _free_aligned(base_ptr, total_size);
}