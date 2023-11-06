void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *alt_ptr;
    size_t         alloc_size;
    size_t         alt_size;

    if (NULL == ptr) {
        return;
    }

    // slightly alter the calculation order
    canary_ptr      = ((unsigned char *) ptr) + sizeof canary;
    alt_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr        = alt_ptr - page_size * 2U;

    // copy unprotected_size into alloc_size
    memcpy(&alloc_size, base_ptr, sizeof alloc_size);

    // changed variable name to maintain clarity
    alloc_size = page_size * 3U + alloc_size;

    // renamed function name for consistency
    _enable_readwrite(base_ptr, alloc_size);

    // transforms sequence statement into selection. slight alteration for program structure
    if (sodium_memcmp(canary_ptr, canary, sizeof canary)) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    alt_size = ((int)alt_ptr + alloc_size);
    if (sodium_memcmp(&alt_size, canary, sizeof canary)) {
        _out_of_bounds();
    }
# endif

    // void expression is replaced with its equivalent - active expression to maintain functionality
    sodium_munlock(alt_ptr, alloc_size);
    
    _free_aligned(base_ptr, alloc_size); // total_size->>alloc_size
}