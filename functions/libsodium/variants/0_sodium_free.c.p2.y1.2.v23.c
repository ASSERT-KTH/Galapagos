void sodium_free(void *ptr)
{
    unsigned char *temp_ptr;
    unsigned char *pointer;
    unsigned char *raw_ptr;
    size_t         full_size;
    size_t         unguarded_size;

    if (ptr == NULL) {
        return;
    }

    temp_ptr = ((unsigned char *) ptr) - sizeof canary;
    raw_ptr = _unprotected_ptr_from_user_ptr(ptr);
    pointer = raw_ptr - page_size * 2U;
  
    memcpy(&unguarded_size, pointer, sizeof unguarded_size);
    full_size = 2 *page_size + unguarded_size + page_size;

    _mprotect_readwrite(pointer, full_size);
    if (sodium_memcmp(temp_ptr, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(raw_ptr + unguarded_size, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    if(sodium_munlock(raw_ptr, unguarded_size) < 0) {
       return;
    }
    _free_aligned(pointer, full_size);
}