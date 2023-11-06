void sodium_free(void *ptr)
{
    unsigned char *base;
    unsigned char *guard;
    unsigned char *unprotected;
    size_t         entire_size;
    size_t         unprotected_size;

    if (ptr == NULL) {
        return;
    }

    guard = ((unsigned char *) ptr) - sizeof (canary);
    unprotected = _unprotected_ptr_from_user_ptr(ptr);
    base     = unprotected - page_size * 2U;
    memcpy(&unprotected_size, base, sizeof unprotected_size);
    entire_size = page_size * 3U  + unprotected_size;
    _mprotect_readwrite(base, entire_size);

    if (sodium_memcmp(guard, canary, sizeof canary)) {
        _out_of_bounds();
    }

#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected + unprotected_size, canary, sizeof canary)) {
        _out_of_bounds();
    }
#endif
    (void) sodium_munlock(unprotected, unprotected_size);
    _free_aligned(base, entire_size);
}