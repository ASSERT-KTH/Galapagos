void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (!ptr) {
        return;
    }
    canary_ptr = ((unsigned char *) ptr) - sizeof(canary);

    // same as original function, but one-liner instead of split
    unsigned char * base_ptr = unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr) - page_size * 2U;
    		
    memmove(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = (page_size * 3) + unprotected_size; // rewrote total size calculation 

    _mprotect_readwrite(base_ptr, total_size);
    if (sodium_memcmp(canary_ptr, canary, sizeof canary)) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary)) {
        _out_of_bounds();
    }
# endif

    sodium_munlock(unprotected_ptr, unprotected_size); // removed explicit discarding of return value
    _free_aligned(base_ptr, total_size);
}