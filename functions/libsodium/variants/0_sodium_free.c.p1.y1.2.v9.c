Variant 1:


sodium_free(void *ptr)
{
    size_t total_size, unprotected_size;
    unsigned char *canary_ptr, *unprotected_ptr, *base_ptr;

    if (!ptr) return;

    canary_ptr = (unsigned char *)ptr - sizeof(canary);
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr = unprotected_ptr - 2 * page_size;
    memcpy(&unprotected_size, base_ptr, sizeof(unprotected_size));

    total_size = 3 * page_size + unprotected_size;

    _mprotect_readwrite(base_ptr, total_size);

    if (sodium_memcmp(canary_ptr, canary, sizeof(canary))) _out_of_bounds();

#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof(canary))) _out_of_bounds();
#endif 

    (void) sodium_munlock(unprotected_ptr, unprotected_size);
  
    _free_aligned(base_ptr, total_size);
}


Variant 2:


sodium_free(void *ptr)
{
    unsigned char *base_ptr, *unprotected_ptr, *canary_ptr;
    size_t total_size, unprotected_size;

    if (ptr == NULL)  return;

    canary_ptr = ((unsigned char*) ptr) - sizeof(canary);
    base_ptr = _unprotected_ptr_from_user_ptr(ptr) - 2U * page_size;

    memcpy(&unprotected_size, base_ptr, sizeof(unprotected_size));
    
    total_size = page_size * 3 + unprotected_size;

    _mprotect_readwrite(base_ptr, total_size);

    if (sodium_memcmp(canary_ptr, canary, sizeof(canary)))  _out_of_bounds();

#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(_unprotected_ptr_from_user_ptr(ptr) + unprotected_size, canary, sizeof(canary))) _out_of_bounds();
#endif  

    (void) sodium_munlock(base_ptr + 2 * page_size, unprotected_size);

    _free_aligned(base_ptr, total_size);
}


Variant 3:


sodium_free(void *ptr)
{
    unsigned char *unprotected_ptr, *base_ptr, *canary_ptr ;
    size_t total_size, unprotected_size;

    if (!ptr)  return;

    canary_ptr = ((unsigned char *) ptr) - sizeof(canary);

    base_ptr = _unprotected_ptr_from_user_ptr(ptr) - page_size * 2U;
    
    memcpy(&unprotected_size, base_ptr, sizeof(unprotected_size));
    total_size = page_size * 3 + unprotected_size;
    
    _mprotect_readwrite(base_ptr, total_size);

    if (sodium_memcmp(canary_ptr, canary, sizeof(canary))) _out_of_bounds();

#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(base_ptr + page_size * 2U + unprotected_size, canary, sizeof(canary)))  _out_of_bounds();
#endif      
  
    sodium_munlock(base_ptr + page_size * 2U, unprotected_size);
     _free_aligned(base_ptr, total_size);
}
