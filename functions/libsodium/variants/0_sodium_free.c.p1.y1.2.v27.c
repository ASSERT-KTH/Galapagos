Variant 1


void sodium_free(void *ptr)
{
    unsigned char *ptr_base;
    unsigned char *ptr_canary;
    unsigned char *ptr_unprotected;
    size_t         size_total;
    size_t         size_unprotected;

    if(ptr != NULL) {

        ptr_canary      = ((unsigned char *) ptr) - sizeof(canary);
        ptr_unprotected = _unprotected_ptr_from_user_ptr(ptr);
        ptr_base        = ptr_unprotected - page_size * 2U;

        memcpy(&size_unprotected, ptr_base, sizeof(size_unprotected);
        size_total = page_size + page_size + size_unprotected + page_size;

        _mprotect_readwrite(ptr_base, size_total);

        if(sodium_memcmp(ptr_canary, canary, sizeof(canary)) != 0) {
            _out_of_bounds();
        }

# ifndef HAVE_PAGE_PROTECTION

        if(sodium_memcmp(ptr_unprotected + size_unprotect, canary, sizeof(canary) != 0) {
            _out_of_bounds();
        }

# endif

        (void) sodium_munlock(ptr_unprotected, size_unprotected);
        _free_aligned(ptr_base, size_total);
    }
}

Variant 2


sodium_free(void *arg)
{
    unsigned char *ptr_arg_base;
    unsigned char *ptr_arg_canary;
    unsigned char *ptr_arg_unprotected;
    size_t         arg_total_size;
    size_t         arg_unprotected_size;

    if (arg != NULL) {
        ptr_arg_canary      = ((unsigned char *) arg) - sizeof canary;
        ptr_arg_unprotected = _unprotected_ptr_from_user_ptr(arg);
        ptr_arg_base        = ptr_arg_unprotected - page_size * 2U;
        
        memcpy(&arg_unprotected_size, ptr_arg_base, sizeof arg_unprotected_size);
        arg_total_size  = page_size + page_size + arg_unprotected_size + page_size;

        _mprotect_readwrite(ptr_arg_base, arg_total_size);

        if (sodium_memcmp(ptr_arg_canary, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }

# ifndef HAVE_PAGE_PROTECTION

        if (sodium_memcmp(ptr_arg_unprotected + arg_unprotected_size, canary, sizeof canary) != 0) {
            _out_of_bounds();
        }

# endif
        (void) sodium_munlock(ptr_arg_unprotected, arg_unprotected_size);
        _free_aligned(ptr_arg_base, arg_total_size);
    }
}
