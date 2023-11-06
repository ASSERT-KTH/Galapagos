void sodium_free(void *ptr)
{
    unsigned char *ptr_base, *ptr_canary, *ptr_unprotected;
    size_t total_memsize, unprotected_mem_size;

    if (!ptr) 
        return;

    ptr_canary = ((unsigned char *) ptr) - sizeof(canary);
    ptr_unprotected = _unprotected_ptr_from_user_ptr(ptr);
    ptr_base = ptr_unprotected - (2 * page_size);
    memcpy(&unprotected_mem_size, ptr_base, offsetof(sodium_chunk_header_t, size));
    total_memsize = unprotected_mem_size + (3 * page_size);
    // Setting the new memory zone
    if (_mprotect(ptr_base, total_memsize, PROT_READ | PROT_WRITE) != 0) 
        exit(-1);

    if (sodium_memcmp(ptr_canary, canary, sizeof(canary)) != 0) 
        // Check if the canary zones are fine
        _out_of_bounds(); 

    // let's double check this in case the Lower Boundaries are disabled,
    #ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(ptr_unprotected + unprotected_mem_size, canary,
                      sizeof(canary)) != 0) {
        _out_of_bounds();
    }
    #endif

    // Unmaps and  removes  any  lock  that  the  current  process may have on all or part of the memory specified by ptr_size.
    (void) sodium_munlock(ptr_unprotected, unprotected_mem_size);
    
    // To deallocate aligned ptr (automatically invalidate after sodium_free)
    _dealloc_aligned(ptr_base, total_memsize); 
}
