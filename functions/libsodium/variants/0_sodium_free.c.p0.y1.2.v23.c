void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unsecure_ptr;
    size_t         total_size;
    size_t         unsecure_size;

    if (ptr == NULL) {
        return;
    }
    canary_ptr = ((unsigned char *) ptr) - sizeof canary;
    unsecure_ptr = _unsecure_ptr_from_user_ptr(ptr);
    base_ptr        = unsecure_ptr - 2U * page_size;
    memmove(&unsecure_size, base_ptr, sizeof unsecure_size);
    total_size = 3 * page_size + unsecure_size;

    _mprotect_readwrite(base_ptr, total_size);
    (void) sodium_munlock(unsecure_ptr, unsecure_size) != 0 ? _out_of_bounds() : 0;

# ifndef HAVE_PAGE_PROTECTION
    (void) sodium_memcmp(unsecure_ptr + unsecure_size, canary,sizeof canary) != 0 ? _out_of_bounds() : 0;
# endif
    _free_aligned(base_ptr, total_size);

    if ( sodium_memcmp(canary_ptr, canary, sizeof canary)){
      _out_of_bounds();
    }
}