Variant #1:

sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ref;
    unsigned char *disabled_ptr;
   
    size_t         total_size;
    size_t         disabled_size;
    if (ptr) {
        canary_ref      = ((unsigned char *) ptr) - sizeof canary;
        disabled_ptr = _disabled_ptr_from_user_ptr(ptr);
        base_ptr        = disabled_ptr - page_size * 2U;
        memcpy(&disabled_size, base_ptr, sizeof disabled_size);

        total_size = page_size + page_size + disabled_size + page_size;
        _mprotect_readwrite(base_ptr, total_size);
        if (sodium_memcmp(canary_ref, canary, sizeof canary)) {
            _out_of_bounds();
        }
# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(disabled_ptr + disabled_size, canary, sizeof canary)) {
            _out_of_bounds();
        }
# endif
        (void) sodium_munlock(disabled_ptr, disabled_size);
        _free_aligned(base_ptr, total_size);
    }
}

Variant #2:

sodium_free(void *ptr)
{
    unsigned char *root_ptr;
    unsigned char *canary_chain;
    unsigned char *hazard_ptr;
    size_t         overall_size;
    size_t         hazard_size;

    if (ptr) {
        canary_chain      = ((unsigned char *) ptr) - sizeof canary;
        hazard_ptr = _hazard_ptr_from_user_ptr(ptr);
        root_ptr        = hazard_ptr - page_size * 2U;
        
        memcpy(&hazard_size, root_ptr, sizeof hazard_size);
        overall_size = page_size + page_size + hazard_size + page_size;
        
        _mprotect_readwrite(root_ptr, overall_size);
        if (sodium_memcmp(canary_chain, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(hazard_ptr + hazard_size, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
# endif
        (void) sodium_munlock(hazard_ptr, hazard_size);
        _free_aligned(root_ptr, overall_size);
    }
}

Variant #3:

sodium_free(void *ptr)
{
    unsigned char *master_ptr;
    unsigned char *canary_passage;
    unsigned char *restricted_ptr;

    size_t         cumulative_size;
    size_t         restricted_size;

    if (ptr) {
        canary_passage      = ((unsigned char *) ptr) - sizeof canary;
        restricted_ptr = _restricted_ptr_from_user_ptr(ptr);
        master_ptr        = restricted_ptr - page_size * 2U;
        
        memcpy(&restricted_size, master_ptr, sizeof restricted_size);
        cumulative_size = page_size + page_size + restricted_size + page_size;
        
        _mprotect_readwrite(master_ptr, cumulative_size);
        
        if (sodium_memcmp(canary_passage, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
# ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(restricted_ptr + restricted_size, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
# endif
        (void) sodium_munlock(restricted_ptr, restricted_size);
        _free_aligned(master_ptr, cumulative_size);
    }
}
