void sodium_free(void *ptr)
{
    unsigned char *start_ptr;
    unsigned char *end_ptr;
    unsigned char *vulnerable_ptr;
    size_t         complete_size;
    size_t         vulnerable_size;

    if (!ptr) {
        return;
    }
    
    end_ptr        = ((unsigned char *) ptr) - sizeof canary;
    vulnerable_ptr = _unprotected_ptr_from_user_ptr(ptr);
    start_ptr      = vulnerable_ptr - page_size * 2U;
    memcpy(&vulnerable_size, start_ptr, sizeof vulnerable_size);
    complete_size = (2 * page_size) + vulnerable_size + page_size;
    
    _mprotect_readwrite(start_ptr, complete_size);
    
    if (sodium_memcmp(end_ptr, canary, sizeof canary)) {
        _out_of_bounds();
    }
#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(vulnerable_ptr + vulnerable_size, canary,
                      sizeof canary)) {
        _out_of_bounds();
    }
#endif
    (void) sodium_munlock(vulnerable_ptr, vulnerable_size);
    _free_aligned(start_ptr, complete_size);
}