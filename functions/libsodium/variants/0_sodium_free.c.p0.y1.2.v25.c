void sodium_free(void *ptr)
{
    if (ptr == NULL) 
        return;

    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_bytes;
    size_t         unprotected_bytes;

    canary_ptr = ((unsigned char *) ptr) - sizeof canary;
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr = unprotected_ptr - 2 * page_size;

    memcpy(&unprotected_bytes, base_ptr, sizeof unprotected_bytes);

    total_bytes = (3 * page_size) + unprotected_bytes;
  
    _mprotect_readwrite(base_ptr, total_bytes);
   
    if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0) 
        _out_of_bounds();
#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_bytes, canary, sizeof canary) != 0) 
        _out_of_bounds();
#endif
    sodium_munlock(unprotected_ptr, unprotected_bytes);
   
    _free_aligned(base_ptr, total_bytes); 
}