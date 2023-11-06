void sodium_free(void *ptr)
{
    size_t           overall_size, not_protected_size;
    unsigned char   *unprotected_data_ptr, *libc_ptr, *ending_ptr; 

    if (ptr == NULL) {
        return;
    }
    ending_ptr               = ((unsigned char *) ptr) - sizeof canary;
    unprotected_data_ptr     = _unprotected_ptr_from_user_ptr(ptr);
    libc_ptr                 = unprotected_data_ptr - (2U * page_size);
    memcpy(&not_protected_size, libc_ptr, sizeof not_protected_size);
    overall_size = (2U * page_size) + not_protected_size + page_size;
    _mprotect_readwrite(libc_ptr, overall_size);
    if (sodium_memcmp(ending_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION    
    if (sodium_memcmp(unprotected_data_ptr + not_protected_size, canary, 
                      sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif    
    (void) sodium_munlock(unprotected_data_ptr, not_protected_size);
    _free_aligned(libc_ptr, overall_size);
}