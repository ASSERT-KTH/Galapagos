Variant 1:


void sodium_free(void *ptr)
{
    unsigned char *ptrs[3];
    size_t         sizes[2];

    if (ptr == NULL) {
        return;
    }
    ptrs[1]       = ((unsigned char *) ptr) - sizeof canary;
    ptrs[2]       = _unprotected_ptr_from_user_ptr(ptr);
    ptrs[0]       = ptrs[2] - page_size * 2U;
    memcpy(&sizes[0], ptrs[0], sizeof sizes[0]);
    sizes[1] = page_size + page_size + sizes[0] + page_size;
    _mprotect_readwrite(ptrs[0], sizes[1]);
    if (sodium_memcmp(ptrs[1], canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(ptrs[2] + sizes[0], canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
#endif
    (void) sodium_munlock(ptrs[2], sizes[0]);
    _free_aligned(ptrs[0], sizes[1]);
}


Variant 2:


void sodium_free(void *ptr)
{
    unsigned char *base;
    unsigned char *canary_pt;
    unsigned char *un_ptr;
    size_t         total;
    size_t         un_size;

    if (ptr != NULL) {
        canary_pt      = ((unsigned char *) ptr) - sizeof canary;
        un_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base        = un_ptr - page_size * 2U;
        memcpy(&un_size, base, sizeof un_size);
        total = page_size + page_size + un_size + page_size;
        _mprotect_readwrite(base, total);
        if (sodium_memcmp(canary_pt, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(un_ptr + un_size, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
# endif
        (void) sodium_munlock(un_ptr, un_size);
        _free_aligned(base, total);
    }
}

