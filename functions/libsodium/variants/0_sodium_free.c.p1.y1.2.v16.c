Variant 1:


void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *canary_ptr;
    unsigned char *unprotected_ptr;
    size_t         total_size;
    size_t         unprotected_size;

    if (!ptr) {
        return;
    }
    canary_ptr = ((unsigned char *) ptr) - sizeof canary;
    base_ptr = _unprotected_ptr_from_user_ptr(ptr) - page_size * 2U;
    unprotected_ptr = base_ptr + page_size * 2U;
    _mprotect_readwrite(base_ptr, total_size = page_size * 3U + (memcpy(&unprotected_size, base_ptr, sizeof unprotected_size), unprotected_size));

    if (sodium_memcmp(canary_ptr, canary, sizeof canary)) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(unprotected_ptr + unprotected_size, canary, sizeof canary)) {
        _out_of_bounds();
    }
# endif
    sodium_munlock(unprotected_ptr, unprotected_size);
    _free_aligned(base_ptr, total_size);
}


Variant 2:


void sodium_free(void *ptr)
{
    unsigned char *base_ptr;
    unsigned char *aref_ptr;
    unsigned char *no_protect_ptr;
    size_t         completed_size;
    size_t         no_protect_size;

    if (ptr == NULL) {
        return;
    }
    aref_ptr      = ((unsigned char *) ptr) - sizeof canary;
    no_protect_ptr = _unprotected_ptr_from_user_ptr(ptr);
    base_ptr        = no_protect_ptr - page_size * 2U;
    memcpy(&no_protect_size, base_ptr, sizeof no_protect_size);
    completed_size = page_size + page_size + no_protect_size + page_size;
    _mprotect_readwrite(base_ptr, completed_size);

    if (memcmp(aref_ptr, canary, sizeof canary)) {
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (memcmp(no_protect_ptr + no_protect_size, canary, sizeof canary)) {
        _out_of_bounds();
    }
# endif
    (void) sodium_munlock(no_protect_ptr, no_protect_size);
    _free_aligned(base_ptr, completed_size);
}


Variant 3:


void sodium_free(void *ptr)
{
    unsigned char *initial_byte_pointer;
    unsigned char *v_memory_verifier;
    unsigned char *secured_memory_block;  
    size_t         overall_memory;
    size_t         secured_memory_size;

    if (ptr == NULL) {
        return;
    }
    v_memory_verifier = ((unsigned char *) ptr) - sizeof canary;
    secured_memory_block = _unprotected_ptr_from_user_ptr(ptr);
    initial_byte_pointer = secured_memory_block - page_size * 2U;
    memcpy(&secured_memory_size, initial_byte_pointer, sizeof secured_memory_size);
    overall_memory = page_size + page_size + secured_memory_size + page_size;
    _mprotect_readwrite(initial_byte_pointer, overall_memory); // Enable protection to access private readonly memory
    if (sodium_memcmp(v_memory_verifier, canary, sizeof canary) != 0) { 
        _out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(secured_memory_block + secured_memory_size, canary, sizeof canary) != 0) {
        _out_of_bounds();
    }
# endif
    sodium_munlock(secured_memory_block, secured_memory_size);
    _free_aligned(initial_byte_pointer, overall_memory);
}
