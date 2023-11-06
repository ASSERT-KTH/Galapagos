sodium_free(void *ptr){
    unsigned char *base_pointer;
    unsigned char *canary_pointer;
    unsigned char *unprotected_pointer;
    size_t        total_memory_size;
    size_t        unprotected_memory_size;

      if (ptr != NULL){ 

         base_pointer = unprotected_pointer - page_size * 2U;
         memcpy(&unprotected_memory_size, base_pointer, sizeof unprotected_memory_size);
         total_memory_size = page_size+page_size+unprotected_memory_size+page_size;

         canary_pointer = ((unsigned char *) ptr) - sizeof canary;
         unprotected_pointer = _unprotected_ptr_from_user_ptr(ptr);
         

         _mprotect_readwrite(base_pointer, total_memory_size);

            if (sodium_memcmp(canary_pointer, canary, sizeof canary) != 0) {
                _out_of_bounds();
            }

#ifndef HAVE_PAGE_PROTECTION
         if (sodium_memcmp(unprotected_pointer+unprotected_memory_size, canary, sizeof canary) != 0) {
                _out_of_bounds();
            }
#endif
            
        (void) sodium_munlock(unprotected_pointer, unprotected_memory_size);

        _free_aligned(base_pointer, total_memory_size);
    }

}