void sodium_free(void *ptr)
{
    size_t total_size;
    size_t unprotected_size;
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
   
    if (ptr != NULL) {
        canary_ptr = ((unsigned char *) ptr) - sizeof canary;
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
        base_ptr = unprotected_ptr - page_size * 2U;
        
        memmove(&unprotected_size, base_ptr, sizeof unprotected_size);
        total_size = (page_size * 2) + unprotected_size + page_size;
        
        _mprotect_readwrite(base_ptr, total_size);
        if (sodium_memcmp(canary, canary_ptr, sizeof canary) != 0) {
            _out_of_bounds();
        }
#ifndef HAVE_PAGE_PROTECTION
        if (sodium_memcmp(canary, unprotected_ptr + unprotected_size, sizeof canary) != 0) {
            _out_of_bounds();
        }
#endif
        sodium_munlock(unprotected_ptr, unprotected_size);
        _free_aligned(base_ptr, total_size);
    }
}
Here, instead of directly using memcpy to copy the content from one memory area to another, I decided to use memmove. It is algorithmically equivalent to memcpy, but safe to use when the source and destination overlap. Secondly, I slightly rearranged the order of parameters in sodium_memcmp for source and destination. These transformations keep the behavior same.