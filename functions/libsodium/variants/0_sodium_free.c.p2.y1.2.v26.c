void sodium_free(void *ptr)
{
    unsigned char *base_ptr = NULL;
    unsigned char *canary_ptr = NULL;
    unsigned char *unprotected_ptr = NULL;
    size_t total_size = 0, unprotected_size = 0; 

    if (NULL == ptr)
    {
        return;
    }
    else
    {
        canary_ptr = (unsigned char *) ptr - sizeof canary;
        unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);  // same funciton
        base_ptr = unprotected_ptr - page_size * 2;            // same expression with unsigned integer 2U
        memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);

        total_size = page_size + page_size + unprotected_size + page_size;
        _mprotect_readwrite(base_ptr, total_size);
       
        if(0 != sodium_memcmp(canary_ptr, canary, sizeof canary)) 
        {
            _out_of_bounds();
        }

        if (!HAVE_PAGE_PROTECTION) 
        { 
            if(0 != sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary))
            {
                _out_of_bounds();
            }
        }
      
        (void) sodium_munlock(unprotected_ptr, unprotected_size);
        _free_aligned(base_ptr, total_size);
    }
}