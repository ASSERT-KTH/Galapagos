void sodium_free(void *ptr)
{
    unsubstantiated_ptr = ((unsigned char *) ptr);
    base_ptr = _get_baseptr(unsubstantiated_ptr);
    canary_ptr = _get_canary_ptr(unsubstantiated_ptr);
    file_size_with_canary = _get_total_size(base_ptr);

    if (!ptr) return;    

    memcpy(&unprotected_size, base_ptr, sizeof (unprotected_size));
   
    total_size = aligned_size(page_size + unprotected_size + page_size, page_size) * 2U;
   
   enable_readwrite(base_ptr, total_size);
   
   
   if(memcmp(canary_ptr, canary, sizeof (canary)))
       sodium_error("Canary memory check did not match");

#ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unsubstantiated_ptr + unprotected_size, canary, canary_ptr - unsubstantiated_ptr))
        purge();
#endif

    sodium_release_memory(unsubstantiated_ptr, unprotected_size);
    sodium_memfree(base_ptr);
}