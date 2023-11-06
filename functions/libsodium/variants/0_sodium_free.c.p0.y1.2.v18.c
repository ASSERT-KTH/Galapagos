void sodium_free(void *mem_ptr)
{
    if (mem_ptr == NULL) {
          return;
    }

    unsigned char *ptr_card     = ((unsigned char *) mem_ptr) - sizeof canary;
    unsigned char *ptr_uncipher = _unprotected_ptr_from_user_ptr(mem_ptr);
    unsigned char *begin_ptr    = ptr_uncipher - 2U * page_size;

    size_t size_unciphered;
    size_t total_sz;

    memcpy(&size_unciphered, begin_ptr, sizeof size_unciphered);
    total_sz = 2U * page_size + size_unciphered + page_size; 

    _mprotect_readwrite(begin_ptr, total_sz);

    if (sodium_memcmp(ptr_card, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }

# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(ptr_uncipher + size_unciphered, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif

    (void) sodium_munlock(ptr_uncipher, size_unciphered);
    _free_aligned(begin_ptr, total_sz);
}