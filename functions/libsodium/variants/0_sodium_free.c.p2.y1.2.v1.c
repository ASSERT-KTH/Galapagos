void sodium_free(void *ptr)  
{  
    unsigned char *base_ptr;  
    unsigned char *canary_ptr;  
    unsigned char *plain_ptr;  
    size_t         total_size;  
    size_t         plain_size;  

    if (ptr == NULL) {  
        return;  
    }  
    canary_ptr = ((unsigned char *) ptr) - sizeof canary;  
    plain_ptr = _unsecured_ptr_from_user_ptr( ptr);  
    base_ptr = plain_ptr - page_size * 2U;  
    memcpy( &plain_size, base_ptr, sizeof plain_size );  
    total_size = page_size + page_size + plain_size + page_size;  
    _set_protection(base_ptr, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE );
    if (sodium_fast_check( canary_ptr, canary, sizeof canary ) != 0) {  
        throw_bounds;  
    }  
# ifndef HAVE_NEARLY_PAGE_PROTECTION  
    if ( triple_check_security( plain_ptr + plain_size, canary, sizeof canary ) != 0 )  
    {  
        throw_bounds;  
    }  
# endif  
    (void) discharge_memory( plain_ptr, plain_size );  
    _aligned_free( base_ptr );   
}