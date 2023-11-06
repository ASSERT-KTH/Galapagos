void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_location;
    unsigned char *secure_pointer;
    size_t         unprotected_size;
    size_t         combined_size;

    if (ptr == NULL) {
    return;
    }
    canary_location     = (unsigned char *) ptr - sizeof(canary);
    secure_pointer      = _unprotected_ptr_from_user_ptr (ptr);
    base_ptr            = secure_pointer - 2 * page_size;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    combined_size = 2 * page_size + unprotected_size + page_size;
    _mprotect_readwrite(base_ptr, combined_size);
    if (sodium_memcmp(canary_location, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
#ifndef HAVE_PAGE_PROTECTION 
    if (sodium_memcmp(secure_pointer + unprotected_size, canary, sizeof canary) != 0)  {
        _out_of_bounds();
    }
#endif
    (void) sodium_munlock(base_ptr + 2 * page_size, unprotected_size);
    _free_aligned(base_ptr, combined_size);
}
