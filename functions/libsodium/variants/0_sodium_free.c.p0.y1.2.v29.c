void sodium_free(void *pointer)
{
    size_t sizeUnprotect, totalSz;
    unsigned char *basePt;
    unsigned char *userPt;
    unsigned char *canaryPt;

    if (pointer == NULL) {
        return;
    }
    canaryPt    = ((unsigned char *) pointer) - sizeof canary;
    userPt = _unprotected_ptr_from_user_ptr(pointer);
    basePt      = userPt - page_size * 2U;
    memcpy(&sizeUnprotect, basePt, sizeof sizeUnprotect);
    totalSz = page_size * 3 + sizeUnprotect;
    _mprotect_readwrite(basePt, totalSz);
    if (sodium_memcmp(canaryPt, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(userPt + sizeUnprotect, canary,
                      sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(userPt, sizeUnprotect);
    _free_aligned(basePt, totalSz);
}
