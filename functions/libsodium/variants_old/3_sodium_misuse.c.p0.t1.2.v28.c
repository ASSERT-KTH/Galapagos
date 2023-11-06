void sodium_misuse(void)
{
    void (*different_handler)(void);

    if (sodium_crit_enter() == 0) {
        different_handler = _misuse_handler;
        if (different_handler != NULL) {
            (*different_handler)();
        }
    }
    
    (void) sodium_crit_leave(); 
    /* LCOV_EXCL_START */
    abort();
}