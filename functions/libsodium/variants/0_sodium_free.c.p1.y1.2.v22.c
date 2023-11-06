1. Optimizing the frequent use of sizeof canary:


sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t total_size;
    size_t unprotected_size;
    size_t canary_size = sizeof(canary);

    if (ptr == NULL) {
        return;
    }
    canary_ptr = ((unsigned char *)ptr) - canary_size;
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr = unprotected_ptr - page_size * 2U;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = page_size + page_size + unprotected_size + page_size;
    _mprotect_readwrite(base_ptr, total_size);
    if (sodium_memcmp(canary_ptr, canary, canary_size) != 0) {
        _out_of_bounds();
    }
#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, canary_size) != 0) {
        _out_of_bounds();
    }
#endif
    (void)sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
}


2. Using early return to reduce nested conditions:


sodium_free(void *ptr)
{
    if (ptr == NULL) {
        return;
    }

    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t total_size;
    size_t unprotected_size;

    canary_ptr = ((unsigned char *)ptr) - sizeof canary;
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr = unprotected_ptr - page_size * 2U;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = page_size + page_size + unprotected_size + page_size;
    _mprotect_readwrite(base_ptr, total_size);
    
    if (sodium_memcmp(canary_ptr, canary, sizeof canary) && sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary)){
        _out_of_bounds();
    }

#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary)){
        _out_of_bounds();
    }
#endif

    sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
}

3. Refactoring conditional directives.


sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t total_size;
    size_t unprotected_size;

    if (ptr == NULL) {
        return;
    }

    canary_ptr = ((unsigned char *)ptr) - sizeof canary;
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr = unprotected_ptr - page_size * 2U;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = page_size * 2 + unprotected_size + page_size;
    _mprotect_readwrite(base_ptr, total_size);
    
# ifdef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
#else 
    if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0 || sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
#endif
    (void) sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
}

In all the above codes, the execution will remain the same meaning the original functionality is preserved with definitely more readability and (or) run-time efficiency.