void sodium_free(void *ptr)
{
    unsigned char *derived_ptr;
    unsigned char *protective_ptr;
    unsigned char *usr_ptr;
    size_t         complete_size;
    size_t         usr_size;

    if (ptr == NULL) {
        return;
    }
    protective_ptr = ((unsigned char *) ptr) - sizeof canary;
    usr_ptr        = _unprotected_ptr_from_user_ptr(ptr);
    derived_ptr    = usr_ptr - page_size * 2U;
    memcpy(&usr_size, derived_ptr, sizeof usr_size);
    complete_size = page_size + page_size + usr_size + page_size;
    _mprotect_readwrite(derived_ptr, complete_size);
    if (sodium_memcmp(protective_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(usr_ptr + usr_size, canary,
                      sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(usr_ptr, usr_size);
    _free_aligned(derived_ptr, complete_size);
}