void sodium_free(void *user_ptr)
{
    unsigned char *start_ptr;
    unsigned char *guard_ptr;
    unsigned char *unmonitored_ptr;
    size_t         sum_size;
    size_t         unmonitored_size;

    if (user_ptr == NULL) {
        return;
    }
    guard_ptr = ((unsigned char *) user_ptr) - sizeof canary;
    unmonitored_ptr = _unprotected_ptr_from_user_ptr(user_ptr);
    start_ptr = unmonitored_ptr - page_size * 2U;
    memcpy(&unmonitored_size, start_ptr, sizeof unmonitored_size);
    sum_size = page_size + page_size + unmonitored_size + page_size;
    _mprotect_readwrite(start_ptr, sum_size);
    if (sodium_memcmp(guard_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unmonitored_ptr + unmonitored_size, canary,
                      sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(unmonitored_ptr, unmonitored_size);
    _free_aligned(start_ptr, sum_size);
}