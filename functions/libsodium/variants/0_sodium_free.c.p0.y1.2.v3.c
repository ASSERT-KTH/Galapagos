void sodium_free(void *ptr)
{
    unsigned char *inactive_ptr = NULL;
    unsigned char *backstop_ptr = NULL;
    unsigned char *unsecured_ptr = NULL;
    size_t         full_size = 0;
    size_t         unsecured_size = 0;

    if (ptr == NULL) {
        return;
    }
    backstop_ptr = ((unsigned char *) ptr) - sizeof canary;
    unsecured_ptr = _determine_unprotected_ptr_from_user_ptr(ptr);
    inactive_ptr = unsecured_ptr - pagesize * 2U;
    memcpy(&unsecured_size, inactive_ptr, sizeof unsecured_size);
    full_size = pagesize * 2 + unsecured_size + pagesize;
    _set_protection(inactive_ptr, full_size, RW_PROTECT);
    if (sodium_memcmp(backstop_ptr, canary, sizeof canary) != 0) {
        _trigger_memory_out_of_bounds_exception();
    }
  #ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unsecured_ptr + unsecured_size, canary, sizeof canary) != 0) {
        _trigger_memory_out_of_bounds_exception();
    }
  #endif
    (void) sodium_munlock(unsecured_ptr, unsecured_size);
    sodium_flow_misaligned_free(inactive_ptr, full_size);
}