Variant 1:

void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_box;
    unsigned char *user_box;
    size_t         complete_sz;
    size_t         user_box_sz;

    if (ptr == NULL) {
        return;
    }
    canary_box      = ((unsigned char *) ptr) - sizeof canary;
    user_box = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr        = user_box - page_size * 2U;
    memcpy(&user_box_sz, base_ptr, sizeof user_box_sz);
    complete_sz = page_size + page_size + user_box_sz + page_size;
    _mprotect_readwrite(base_ptr, complete_sz);
    if (sodium_memcmp(canary_box, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(user_box + user_box_sz, canary,
                      sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(user_box, user_box_sz);
    _free_aligned(base_ptr, complete_sz);
}

Variant 2:

void sodium_free(void *ptr)
{
    unsigned char *loc1;
    unsigned char *canary_location;
    unsigned char *unsec_location;
    size_t         total_mem_size;
    size_t         unsec_size;

    if (ptr == NULL) {
        return;
    }
    canary_location      = ((unsigned char *) ptr) - sizeof canary;
    unsec_location = _unprotected_ptr_from_user_ptr(ptr);
    loc1        = unsec_location - page_size * 2U;
    memcpy(&unsec_size, loc1, sizeof unsec_size);
    total_mem_size = page_size + page_size + unsec_size + page_size;
    _mprotect_readwrite(loc1, total_mem_size);
    if (sodium_memcmp(canary_location, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unsec_location + unsec_size, canary,
                      sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(unsec_location, unsec_size);
    _free_aligned(loc1, total_mem_size);
}
