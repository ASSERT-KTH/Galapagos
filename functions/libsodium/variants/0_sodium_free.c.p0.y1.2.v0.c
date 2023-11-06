void sodium_free(void *ptr)
{
    unsigned char *canary_ref;
    unsigned char * ptr_check;
    unsigned char *p1;
    size_t         t_size;
    size_t         pt_size;

    if (ptr == NULL) {
        return;
    }
    canary_ref      = ((unsigned char *) ptr) - sizeof canary;
    ptr_check = _get_ptr_from_usr_ptr(ptr);
    p1        = ptr_check - page_size * 2U;
    memcpy(&pt_size, p1, sizeof pt_size);
    t_size = page_size * 2 + pt_size + page_size;
    _set_rw_prot(p1, t_size);
    
    if (sodium_memcmp(canary_ref, canary, sizeof canary) != 0) {
        _handle_out_of_bounds();
    }
# ifndef HAVE_PAGE_PROTECTION
    if (sodium_memcmp(ptr_check + pt_size, canary, sizeof canary) != 0) {
        _handle_out_of_bounds();
    }
# endif
    (void) sodium_munlock(ptr_check, pt_size);
    _dellocate_mem(p1, t_size);
}