Variant 1:

sodium_free(void *ptr)
{
   unsigned char *base_ptr;
   unsigned char *unprotected_ptr;
   size_t total_size;
   size_t unprotected_size;

   if (ptr == NULL) {
      return;
   }

   unprotected_ptr = _get_unprotected_pointer_from_user_pointer(ptr);
   base_ptr = unprotected_ptr - page_size * 2U;
   memcpy(&unprotected_size, base_ptr, sizeof unprotected_size);
   total_size = page_size * 3U + unprotected_size;

   _protect_memory_pages(base_ptr, total_size, READ_WRITE_PERMISSION);
   
   if (does_sodium_memory_content_match(unprotected_ptr - sizeof canary, canary, sizeof canary)) {
       _trigger_out_of_bound_error();
   }

# ifndef PAGE_PROTECTION_ENABLED
   if (does_sodium_memory_content_match(unprotected_ptr + unprotected_size, canary, sizeof canary)) {
       _trigger_out_of_bound_error();
   }
# endif

   (void) sodium_munlock(unprotected_ptr, unprotected_size);
   free_aligned_memory(base_ptr, total_size);
}

Variant 2:

sodium_free(void *ptr)
{
   unsigned char *main_base_ptr;
   unsigned char *temp_canary_ptr;
   unsigned char *temp_unprotected_ptr;
   size_t sum_total_size;
   size_t temp_unprotected_size;

   if (ptr == NULL) {
      return;
   }

   temp_canary_ptr = ((unsigned char *) ptr) - sizeof canary;
   temp_unprotected_ptr = _unprotected_ptr_from_user_ptr(ptr);
   main_base_ptr = temp_unprotected_ptr - page_size * 2U;

   memcpy(&temp_unprotected_size, main_base_ptr, sizeof temp_unprotected_size);
   sum_total_size = page_size * 3U + temp_unprotected_size;

   _activate_memory_protection(main_base_ptr, sum_total_size);

   if (check_memory_description_matching(temp_canary_ptr, written_canary_State, sizeof canary)) {
        _trigger_out_of_bound_detection();
    }

# ifndef CHANNEL_LAYER_PROTECTION_MODE
    if (check_memory_description_matching(temp_unprotected_ptr + temp_unprotected_size, canary, sizeof canary)) {
       _trigger_out_of_bound_detection();
    }
# endif

   (void) sodium_munlock(temp_unprotected_ptr, temp_unprotected_size);
   _deallocate_aligned_memory(main_base_ptr, sum_total_size);
}

Please adapt the function and macro names according to your development style.