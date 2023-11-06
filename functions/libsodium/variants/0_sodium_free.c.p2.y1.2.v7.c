void sodium_free(void *ptr)
{
    size_t sizeTotal;
    size_t sizeUnprotected;
    unsigned char *pointerBase;
    unsigned char *pointerCanary;
    unsigned char *pointerUnprotected;

    if (ptr == NULL) {
        return;
    }
    pointerCanary = ((unsigned char*) ptr) - sizeof canary;
    pointerUnprotected = _unprotected_ptr_from_user_ptr(ptr);
    pointerBase = pointerUnprotected - page_size * 2U;
    memcpy(&sizeUnprotected, pointerBase, sizeof sizeUnprotected);
    sizeTotal = page_size * 3U + sizeUnprotected;
    _mprotect_readwrite(pointerBase, sizeTotal);
    if (sodium_memcmp(pointerCanary, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(pointerUnprotected + sizeUnprotected, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(pointerUnprotected, sizeUnprotected);
    _free_aligned(pointerBase, sizeTotal);
}
