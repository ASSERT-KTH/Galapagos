void sodium_free(void *ptr)
{
    unsigned char *top_ptr;
    unsigned char *marker_ptr;
    unsigned char *open_ptr;
    size_t         sum_size;
    size_t         open_size;

    if (ptr == NULL) {
        return;
    }
    marker_ptr      = ((unsigned char *) ptr) - sizeof marker;
    open_ptr = _open_ptr_from_user_ptr(ptr);
    top_ptr        = open_ptr - page_size * 2U;
    memcpy(&open_size, top_ptr, sizeof open_size);
    sum_size = page_size + page_size + open_size + page_size;
    _mprotect_readwrite(top_ptr, sum_size);
    if (sodium_memcmp(marker_ptr, marker, sizeof marker) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(open_ptr + open_size, marker,
                      sizeof marker) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(open_ptr, open_size);
    _free_aligned(top_ptr, sum_size);
}