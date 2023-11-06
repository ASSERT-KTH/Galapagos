Version 1:

void sodium_free(void *ptr)
{
    unsigned char *canary_ptr, *unprotected_ptr, *base_ptr;
    size_t total_size, unprotected_size;

    if (ptr) {
        canary_ptr = ((unsigned char *) ptr) - sizeof canary;
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr = unprotected_ptr - (page_size << 1);

        memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);

        total_size = (page_size << 2) + unprotected_size;

        _mprotect_readwrite(base_ptr, total_size);
        if (sodium_memcmp(canary_ptr, canary, sizeof canary)) {
           _out_of_bounds();
        }
#ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(unprotected_ptr + unprotected_size, canary,
                      sizeof canary) != 0) {
            _out_of_bounds();
        }
#endif
    sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
    }
}

Version 2:

void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (ptr) {

        canary_ptr      = ((unsigned char *) ptr) - sizeof canary;
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr        = unprotected_ptr - (page_size * 2U);
        void            *_ptr = base_ptr;
        memcpy(&unprotected_size, _ptr, sizeof unprotected_size);
        
        _ptr            += sizeof unprotected_size;

        total_size = (page_size * 3) + unprotected_size;

        _mprotect_readwrite(base_ptr, total_size);

        if (0 != sodium_memcmp(canary_ptr, canary, sizeof canary)) {
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
}

Version 3:

void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (ptr) {

        canary_ptr      = ((unsigned char *) ptr) - sizeof canary;
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr        = unprotected_ptr;
        unprotected_ptr -= 2 * page_size;

        memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
        
        total_size = (4 * page_size) + unprotected_size;

        _mprotect_readwrite(base_ptr, total_size);

        if (0 != sodium_memcmp(canary_ptr, canary, sizeof canary)) {
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
}
