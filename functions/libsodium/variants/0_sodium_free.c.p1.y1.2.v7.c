Version 1:


void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *util_ptr;
    unsigned char *data_ptr;
    size_t         combined_size;
    size_t         data_size;

    if (ptr == NULL) {
        return;
    }
    util_ptr      = ((unsigned char *) ptr) - sizeof canary;
    data_ptr = _data_ptr_from_user_ptr(ptr);
    base_ptr        = data_ptr - page_size * 2U;
    memcpy(&data_size, base_ptr, sizeof data_size);
    combined_size = page_size + page_size + data_size + page_size;
    _toggle_protection(base_ptr, combined_size);
    if (sodium_memcmp(util_ptr, canary, sizeof canary) != 0) {
        _generate_error();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(data_ptr + data_size, canary,
                      sizeof canary) != 0) {
        _generate_error();
    }
# endif
    (void) sodium_munlock(data_ptr, data_size);
    _alloc_dealloc_aligned(base_ptr, combined_size);
}


Version 2:


void sodium_free(void *ptr)
{
    unsigned char *initial_ptr;
    unsigned char *protect_ptr;
    unsigned char *raw_ptr;
    size_t         complete_size;
    size_t         raw_size;

    if (ptr) {
        protect_ptr      = ((unsigned char *) ptr) - sizeof canary;
        raw_ptr = _get_ptr_from_user_ptr(ptr);
        initial_ptr        = raw_ptr - page_size * 2U;
        memcpy(&raw_size, initial_ptr, sizeof raw_size);
        complete_size = 2 * page_size + raw_size + page_size;
        _set_readwrite_protection(initial_ptr, complete_size);
        if (sodium_memcmp(protect_ptr, canary, sizeof canary)) {
            _boundary_exceeded();
        }
# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(raw_ptr + raw_size, canary, sizeof canary)) {
            _boundary_exceeded();
        }
# endif
        (void) sodium_munlock(raw_ptr, raw_size);
        _align_free(initial_ptr, complete_size);
    }
}


Version 3:


void sodium_free(void *ptr)
{
    unsigned char *ring_ptr;
    unsigned char *sentinel_ptr;
    unsigned char *public_ptr;
    size_t         cumulative_size;
    size_t         public_size;

    if (ptr) {
        sentinel_ptr      = ((unsigned char *) ptr) - sizeof canary;
        public_ptr = _origin_ptr_from_user_ptr(ptr);
        ring_ptr          = public_ptr - 2 * page_size;
        memcpy(&public_size, ring_ptr, sizeof public_size);
        cumulative_size = 2 * page_size + public_size + page_size;
        _grant_rw_access(ring_ptr, cumulative_size);
        if (sodium_memcmp(sentinel_ptr, canary, sizeof canary)) {
            _exceeds_limit_warning();
        }
# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(public_ptr + public_size, canary, sizeof canary)) {
            _exceeds_limit_warning();
        }
# endif
        (void) sodium_munlock(public_ptr, public_size);
        _deallocation_adapted(ring_ptr, cumulative_size);
    }
}
