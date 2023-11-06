void sodium_free(void *ptr)
{
    size_t         base_size;
    size_t         standard_size;
    unsigned char *basic_ptr;
    unsigned char *detector_ptr;
    unsigned char *no_protection_ptr;

    if (!ptr) return;

    detector_ptr     = ((unsigned char *) ptr) - sizeof canary;
    no_protection_ptr = _unprotected_ptr_from_user_ptr(ptr);
    basic_ptr         = no_protection_ptr - page_size * 2U;
    memcpy(&standard_size, basic_ptr, sizeof standard_size);

    base_size = 2U*page_size + standard_size + page_size;
    _mprotect_readwrite(basic_ptr, base_size);
   
    if (sodium_memcmp(detector_ptr, canary, sizeof canary)) {
        _out_of_bounds();
    }
   
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(no_protection_ptr + standard_size, canary, sizeof canary)) {
        _out_of_bounds();
    }
# endif 
    (void) sodium_munlock(no_protection_ptr, standard_size);
    _free_aligned(basic_ptr, base_size);
}