sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *ptr_to_canary;  //changed this
    unsigned char *non_protected_ptr;   //changed this
    size_t         all_size;
    size_t         non_protected_size;

    if (ptr == NULL) {
        return;
    }
    ptr_to_canary = ((unsigned char *) ptr) - sizeof canary;
    non_protected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr = non_protected_ptr - page_size * 2;
    memcpy(&non_protected_size, base_ptr, sizeof non_protected_size);
    all_size = (page_size * 3) + non_protected_size;
    _mprotect_readwrite(base_ptr, all_size);
    if (sodium_memcmp(ptr_to_canary, canary, sizeof canary)) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(non_protected_ptr + non_protected_size, canary,
                      sizeof canary)) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(non_protected_ptr, non_protected_size);
    _free_aligned(base_ptr, all_size);
}