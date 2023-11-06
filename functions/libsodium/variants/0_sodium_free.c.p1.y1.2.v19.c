Variant 1:

void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    size_t total_size;
    unsigned char *canary_ptr;
    size_t unprotected_size;
    unsigned char *unprotected_ptr;

    if (!ptr) {
        return;
    }
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr   = unprotected_ptr - 2U * page_size;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = unprotected_size + 3U * page_size;
    
    canary_ptr = ((unsigned char *) ptr) - sizeof canary;
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


Variant 2:

void sodium_free(void *ptr)
{
    if (ptr == NULL) 
    {
        return;
    }

    unsigned char *unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    unsigned char *base_ptr = unprotected_ptr - 2U * page_size;

    size_t unprotected_size;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);

    size_t total_size = 3U * page_size + unprotected_size;

    unsigned char *canary_ptr = ((unsigned char *) ptr) - sizeof(canary);

    _mprotect_readwrite(base_ptr, total_size);

    if (0 != sodium_memcmp(canary_ptr, canary, sizeof canary)) 
    {
        _out_of_bounds();
    }

# ifndef HAVE_PAGE_PROTECTION
    if (0 != sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary)) 
    {
        _out_of_bounds();
    }
# endif

    sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
}
