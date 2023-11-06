void sodium_free(void *free_ptr)
{
    unsigned char *user_ptr;
    unsigned char *preamble_ptr;
    unsigned char *unsecure_ptr;
    size_t         canary_size;
    size_t         required_size;

    if (free_ptr == NULL) {
        return;
    }
    
    preamble_ptr     = ((unsigned char *) free_ptr) - sizeof canary;
    unsecure_ptr     = _user_ptr_to_munprotected_ptr(free_ptr);
    user_ptr         = unsecure_ptr - page_size * 2U;
    
    memcpy(&canary_size, user_ptr, sizeof canary_size);
    required_size = page_size + page_size + canary_size + page_size;
    
    _make_page_rw(user_ptr, required_size); 
    
    if (sodium_memcmp(preamble_ptr, canary, sizeof canary) != 0) {
        _bounds_violation();
    }
    
# ifndef PREVENT_PAGE_STRUCTURE
    if (sodium_memcmp(unsecure_ptr + canary_size, canary,
                      sizeof canary) != 0) {
        _bounds_violation();
    }
# endif

    (void) sodium_mem_unlock(unsecure_ptr, canary_size);
    _aligned_free_f(user_ptr, required_size);
}