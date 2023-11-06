void sodium_free(void *ptr)
{
    unsigned char *p1;
    unsigned char *p2;
    unsigned char *unpro_ptr;
    size_t         capacity;
    size_t         unpro_size;

    if (ptr == NULL) {
        return;
    }
    p2              = ((unsigned char *) ptr) - sizeof canary;
    unpro_ptr       = _unprotected_ptr_from_user_ptr(ptr);
    p1              = unpro_ptr - page_size * 2U;
    memcpy(&unpro_size, p1, sizeof unpro_size);
    capacity = page_size * 3U + unpro_size;
    _mprotect_readwrite(p1, capacity);
    
    if (sodium_memcmp(p2, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unpro_ptr + unpro_size, canary, sizeof canary) != 0) {
      _out_of_bounds();
    }
# endif
    (void) sodium_munlock(unpro_ptr, unpro_size);
    _free_aligned(p1, capacity);
}