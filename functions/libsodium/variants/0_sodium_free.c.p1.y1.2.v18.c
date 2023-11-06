Here are two transformed variant versions of the original function which preserve functionality:

**Variant 1: Swapping the pointer order in the _mprotect_readwrite() call**


void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (ptr == NULL) {
        return;
    }
    canary_ptr      = ((unsigned char *) ptr) - sizeof canary;
    unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr        = unprotected_ptr - 2U * page_size;
    memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
    total_size = page_size * 3U + unprotected_size;
    _mprotect_readwrite(total_size, base_ptr);
    if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
    if (!HAVE_PAGE_PROTECTION && sodium_memcmp(unprotected_ptr + unprotected_size, 
                                               canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
    (void) sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
}


**Variant 2: Clarifying the Multiplication Operations**


void sodium_free(void *ptr){
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t   total_size;
    size_t   unprotected_size;

   if(ptr==NULL){
      return;
   }

   canary_ptr = ((unsigned char *) ptr)-sizeof(canary);
   unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
   
   unsigned int double_page_size= page_size * 2U;
   base_ptr=unprotected_ptr-double_page_size;
   
   memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
   
   unsigned int triple_page_size = page_size*3U;
   total_size=triple_page_size+unprotected_size;
   
   _mprotect_readwrite(base_ptr, total_size);
   if (sodium_memcmp(canary_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
   }

#ifndef HAVE_PAGE_PROTECTION   
   if(sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof(canary)) != 0){
       _out_of_bounds();
   }
#endif
   
   (void) sodium_munlock(unprotected_ptr, unprotected_size);
   _free_aligned(base_ptr, total_size);
 }
