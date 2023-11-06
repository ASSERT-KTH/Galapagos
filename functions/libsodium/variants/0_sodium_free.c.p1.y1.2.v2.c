Variant 1:


void sodium_free(void *ptr)
{
    unsigned char *curr_ptr;
    unsigned char *canaryCheck;
    unsigned char *nxt_ptr;
    size_t   totalSize;
    size_t   nxtSize;
    
    if (ptr != NULL) {
        canaryCheck = ((unsigned char *) ptr) - sizeof canary;
        nxt_ptr      = _unprotected_ptr_from_user_ptr(ptr);
        curr_ptr        = nxt_ptr - page_size * 2U;
        memcpy(&nxtSize, curr_ptr, sizeof nxtSize);
        totalSize      = page_size + page_size + nxtSize + page_size;
        
        _mprotect_readwrite(curr_ptr, totalSize);
        
        if (sodium_memcmp(canaryCheck, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }

# ifndef HAVE_PAGE_PROTECTION      
        if(sodium_memcmp(nxt_ptr + nxtSize, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
#endif
        
        (void) sodium_munlock(nxt_ptr, nxtSize);
        
        _free_aligned(curr_ptr, totalSize);
    }

}


Variant 2:


void sodium_free(void *ptr)
{
    unsigned char *primary_ptr;
    unsigned char *guard_ptr;
    unsigned char *open_ptr;
    size_t   actual_size;
    size_t   open_size;

    if(nullptr != ptr) {
        guard_ptr   = (unsigned char *) ptr - sizeof canary;
        open_ptr    = _unprotected_ptr_from_user_ptr(ptr);
        primary_ptr = open_ptr - (2U * page_size);
        
        memcpy(&open_size, primary_ptr, sizeof open_size);
        actual_size = 3 * page_size + open_size;
        
        _mprotect_readwrite(primary_ptr, actual_size);
        
        if(0 != sodium_memcmp(guard_ptr, canary, sizeof canary)) {
            _out_of_bounds();
        }
    
#ifndef HAVE_PAGE_PROTECTION
        if(0 != sodium_memcmp(open_ptr + open_size, canary, sizeof canary)) {
            _out_of_bounds();
        }
#endif
        
        (void) sodium_munlock(open_ptr, open_size);
        _free_aligned(primary_ptr, actual_size);
    }
}
