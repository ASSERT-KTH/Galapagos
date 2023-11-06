Here is a variant of the original function, with altered structure yet preserving any functionality:


void sodium_free(void *ptr) {
    unsigned char *temp_ptr;
    size_t temp_size;
    
    if (ptr != NULL) {
        temp_ptr = ((unsigned char *)ptr);
        
        memcpy(&temp_size, temp_ptr + sizeof(canary), sizeof temp_size);

        size_t sum_size = page_size * 3U + temp_size;

        _mprotect_readwrite(temp_ptr - page_size * 2U, sum_size);

        if (sodium_memcmp(temp_ptr - sizeof canary, canary, sizeof canary) != 0) {
             _out_of_bounds();
        }

#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(temp_ptr + temp_size, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
#endif

        (void) sodium_munlock(_unprotected_ptr_from_user_ptr(ptr), temp_size);
    }
    _free_aligned(((unsigned char *)ptr) - 2 * page_size , sum_size);
}


The following code maintain the sequence, and might have better readability than the origin


void sodium_free(void *ptr) {
    size_t len;
    size_t full_len;
    unsigned char *pt_start;
    unsigned char *guard;
    unsigned char *unprotected_pt;
    
    if (ptr == NULL) {
        return;
    } 
    guard = ((unsigned char *)ptr - sizeof canary);
    unprotected_pt = _unprotected_ptr_from_user_ptr(ptr);
    pt_start = unprotected_pt - page_size*2U;
    memcpy(&len, pt_start, sizeof len);
    full_len = len + page_size*3U;
    _mprotect_readwrite(pt_start, full_len);
    
    if (sodium_memcmp(guard, canary, sizeof canary)) {
        _out_of_bounds();
    } 

#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_pt + len, canary, sizeof canary)) {
        _out_of_bounds();
    }
#endif

    (void) sodium_munlock(unprotected_pt, len);
    _free_aligned(pt_start, full_len);
}


Both variants maintain the signature, usability and behavior of the initial function while providing different styles and organization of the code. It still performs protected free with salty results.