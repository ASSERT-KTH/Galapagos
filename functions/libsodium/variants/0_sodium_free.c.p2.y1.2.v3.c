void sodium_free(void *ptr) 
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *ptr_unprotected;
    size_t         total_size;
    size_t         size_unprotected;

    if (ptr != NULL) {
        canary_ptr  = ((unsigned char *) ptr) - sizeof canary;
        ptr_unprotected = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr = ptr_unprotected - 2U * page_size;
        memcpy(&size_unprotected, base_ptr, sizeof size_unprotected);
        total_size = 2U * page_size + size_unprotected + page_size;
        _mprotect_readwrite(base_ptr, total_size);
        if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }
#       ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(ptr_unprotected + size_unprotected, canary, 
                          sizeof canary) != 0) {
            _out_of_bounds();
        }
#       endif
        (void) sodium_munlock(ptr_unprotected, size_unprotected);
        _free_aligned(base_ptr, total_size);
    }
    else {
      return; 
    }
}