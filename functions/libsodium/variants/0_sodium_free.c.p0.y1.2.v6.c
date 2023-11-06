Here's a reimplementation of the sodium_free function that doesn't fundamentally change how it works:


void sodium_free(void *ptr)
{
    if (!ptr) {
        return;
    }
    unsigned char* base_ptr, * canary_ptr, * unprotected_ptr;
    size_t total_size, unprotected_size;
    
    canary_ptr = ((unsigned char *) ptr) - sizeof canary;
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    
    base_ptr = unprotected_ptr - 2*page_size;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    
    total_size = 2*page_size + unprotected_size + page_size;
    
    _mprotect_readwrite(base_ptr, total_size);
    
    if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }

# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, 
                      sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif

    sodium_munlock(unprotected_ptr, unprotected_size);

    _free_aligned(base_ptr, total_size);
}


The implementation is split to a couple of logical chunks separated by an empty line for better readability. This improvement helps with tracking variable declarations, copying data, applying protections, and comparison.